#ifndef DPAIRE_H
#define DPAIRE_H

#include <iostream>
#include <string>
#include <vector>

#include "Combinaison.h"

class DPaire : public Combinaison
{
    private:


    public:
        int identifier(std::vector<Carte> lesCartes);


};

#endif

