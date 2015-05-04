#ifndef RANDOM_H
#define RANDOM_H



#include <iostream>
#include <string>

#include "Strategie.h"

class Random : public Strategie
{
    private:

    public:
        Random(Joueur *leJoueur):Strategie(leJoueur){};
        int mise();
        bool suivi();

};

#endif
