#ifndef LOOSER_H
#define LOOSER_H

#include <iostream>
#include <string>

#include "State.h"
#include "Joueur.h"

class Looser : public State
{
    private:

    public:
        Looser(Joueur *leJoueur):State(leJoueur){};
        void affichage(int i);
        double combinaison(MainC  jeu);
        void showdown(int i);

};

#endif
