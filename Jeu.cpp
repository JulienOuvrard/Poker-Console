#include <iostream>
#include <vector>
#include <string>
#include "Jeu.h"
#include <time.h>
#include "stdlib.h"

using namespace std;

    //constructeur par defaut
    Jeu::Jeu()
    {
        nbCarte_=0;
        vector<Carte> leJeu_;
        vector<int> numero_;
        nextCard_=0;
    }

    //constructeur avec des cartes et leur nombre
    Jeu::Jeu(int nombreCarte, vector<Carte> leJeu )
    {
        nbCarte_=nombreCarte;
        leJeu_=leJeu;
        vector<int> numero_;
        nextCard_=0;
        melanger();
    }

    //fonction servant a melanger le jeu
    //numero_ correspond a l'ordre des cartes
    void Jeu::melanger()
    {
        numero_.clear();
        int numero;
        bool exist;
        srand(time(NULL));
        for(unsigned int i=0; i<leJeu_.size();i++)
        {
            do
            {
                exist=false;
                numero=rand()%(leJeu_.size());
                for(unsigned int j=0; j<numero_.size();j++)
                {
                    if(numero_.at(j)==numero)
                    {
                        exist=true;
                    }
                }
            }
            while(exist);
            numero_.push_back(numero);
        }
        nextCard_=0;
    }

    //renvoie le nombre de cartes restant dans le jeu
    int Jeu::carteRestante()
    {
        return nbCarte_-nextCard_+1;
    }

    //accesseur get de l'attribut nextCard
    int Jeu::getNextCard()
    {
        return nextCard_;
    }

    //renvoie la carte correspondant a la pioche d'une carte dans le jeu
    Carte Jeu::tirerCarte()
    {
        int j=-1;
        Carte laCarte;
        for(unsigned int i=0; i<numero_.size();i++)
        {
            if(numero_.at(i)==nextCard_)
            {
                j=i;
            }
        }
        laCarte = leJeu_.at(j);
        nextCard_++;

        return laCarte;
    }

