#include <iostream>
#include <string>
#include "Couche.h"


using namespace std;

    //affichage de l'état du joueur
    void Couche::affichage(int i)
    {
        cout << leJoueur_->getName() << " a " << leJoueur_->getLaPartie()->getJoueur(i).getJetons() << " jetons."<<endl;
    }

    //valeur de la combinaison de la main du joueur
    double Couche::combinaison(MainC  jeu)
    {
        return 0;
    }

    //affichage du joueur lors du showdown
    void Couche::showdown(int i)
    {
        cout<<leJoueur_->getName()<<" s'est couche avant la fin du tour"<<endl;
    }
