#ifndef HUMAIN_H
#define HUMAIN_H

#include <iostream>
#include <string>

#include "Joueur.h"

class Humain : public Strategie
{
    private:
        Joueur joueur_;
    public:
        Humain(Joueur *leJoueur):Strategie(leJoueur){};
        int mise();
        bool suivi();
        void affichage();


};

#endif
