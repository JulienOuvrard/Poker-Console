#ifndef PAIRE_H
#define PAIRE_H

#include <iostream>
#include <string>
#include <vector>

#include "Combinaison.h"

class Paire : public Combinaison
{
    private:


    public:
        int identifier(std::vector<Carte> lesCartes);


};

#endif
