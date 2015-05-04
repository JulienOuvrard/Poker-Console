#ifndef POULETTE_H
#define POULETTE_H

#include <iostream>
#include <string>

#include "Strategie.h"

class Poulette : public Strategie
{
    private:

    public:
        Poulette(Joueur *leJoueur):Strategie(leJoueur){};
        int mise();
        bool suivi();

};

#endif
