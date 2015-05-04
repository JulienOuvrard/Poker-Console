#ifndef FLAMBEUR_H
#define FLAMBEUR_H

#include <iostream>
#include <string>

#include "Strategie.h"

class Flambeur : public Strategie
{
    private:

    public:
        Flambeur(Joueur *leJoueur):Strategie(leJoueur){};
        int mise();
        bool suivi();

};

#endif
