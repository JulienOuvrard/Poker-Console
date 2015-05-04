#include <iostream>
#include <string>
#include "EnJeu.h"


using namespace std;

    //affichage de l'état du joueur
   void EnJeu::affichage(int i)
    {
        cout << leJoueur_->getName() << " a " << leJoueur_->getLaPartie()->getJoueur(i).getJetons() << " jetons."<<endl;
    }

    //valeur de la combinaison de la main du joueur
    double EnJeu::combinaison(MainC  jeu)
    {
        return jeu.combinaison();
    }

    //affichage du joueur lors du showdown
    void EnJeu::showdown(int i)
    {
        cout<<leJoueur_->getName()<<" a dans sa main : ";
        leJoueur_->getLaPartie()->getJoueur(i).getCarte(0).afficher();
        cout << " et ";
        leJoueur_->getLaPartie()->getJoueur(i).getCarte(1).afficher();
        cout << endl;
    }


