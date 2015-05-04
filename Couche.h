#ifndef COUCHE_H
#define COUCHE_H

#include <iostream>
#include <string>

#include "State.h"
#include "Joueur.h"

class Couche : public State
{
    private:

    public:
        Couche(Joueur *leJoueur):State(leJoueur){};
        void affichage(int i);
        double combinaison(MainC  jeu);
        void showdown(int i);

};

#endif
