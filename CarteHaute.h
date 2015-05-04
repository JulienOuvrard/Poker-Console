#ifndef CARTEHAUTE_H
#define CARTEHAUTE_H

#include <iostream>
#include <string>
#include <vector>

#include "Combinaison.h"

class CarteHaute : public Combinaison
{
    private:


    public:
        int identifier(std::vector<Carte> lesCartes);


};

#endif

