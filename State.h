#ifndef STATE_H
#define STATE_H

#include <iostream>
#include <string>

#include "Joueur.h"
class Joueur;




class State
{
    protected:
        Joueur *leJoueur_;
    public:
        State(Joueur *leJoueur);
        virtual void affichage(int i)=0;
        virtual double combinaison(MainC jeu)=0;
        virtual void showdown(int i)=0;
};

#endif

