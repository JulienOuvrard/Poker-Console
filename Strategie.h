#ifndef STRATEGIE_H
#define STRATEGIE_H

#include <iostream>
#include <string>
#include "Joueur.h"
class Joueur;

class Strategie
{
    protected:
        Joueur *leJoueur_;
    public:
        Strategie(Joueur *leJoueur);
        virtual int mise()=0;
        virtual bool suivi()=0;

};

#endif
