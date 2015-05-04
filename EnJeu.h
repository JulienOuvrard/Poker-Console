#ifndef ENJEU_H
#define ENJEU_H

#include <iostream>
#include <string>

#include "State.h"
#include "Joueur.h"

class EnJeu : public State
{
    private:

    public:
        EnJeu(Joueur *leJoueur):State(leJoueur){};
        void affichage(int i);
        double combinaison(MainC  jeu);
        void showdown(int i);

};

#endif
