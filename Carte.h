#ifndef CARTE_H
#define CARTE_H

#include <iostream>
#include "Couleur.h"
#include "Valeur.h"


class Carte
{
    private:
        Couleur couleur_;
        Valeur valeur_;

    public:
        Carte();
        Carte(Couleur coul, Valeur val);
        Valeur getValeur();
        Couleur getCouleur();
        void afficher();



};

#endif
