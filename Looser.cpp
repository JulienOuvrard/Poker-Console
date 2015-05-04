#include <iostream>
#include <string>
#include "Looser.h"


using namespace std;

    //affichage de l'état du joueur
    void Looser::affichage(int i)
    {
        cout << leJoueur_->getName() << " has lost the game."<<endl;
    }

    //valeur de la combinaison de la main du joueur
    double Looser::combinaison(MainC  jeu)
    {

        return 0;
    }

    //affichage du joueur lors du showdown
    void Looser::showdown(int i)
    {
        cout<<leJoueur_->getName()<<" n'est plus en jeu"<<endl;
    }
