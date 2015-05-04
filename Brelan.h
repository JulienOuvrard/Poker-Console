#ifndef BRELAN_H
#define BRELAN_H

#include <iostream>
#include <string>
#include <vector>

#include "Combinaison.h"
class Brelan : public Combinaison
{
    private:


    public:
        int identifier(std::vector<Carte> lesCartes);


};

#endif

