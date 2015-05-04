#ifndef COMBINAISON_H
#define COMBINAISON_H

#include <iostream>
#include <vector>

#include "Carte.h"

class Combinaison
{
    private:
        //TODO le Chain of Responsability n'est pas composé de lui meme
    public:
        int virtual identifier(std::vector<Carte> lesCartes)=0;
};

#endif
