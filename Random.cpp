#include <iostream>
#include <string>
#include "Random.h"
#include <stdlib.h>
#include <time.h>



using namespace std;

    //renvoie la mise tentée par le joueur artificiel
    int Random::mise()
    {
        return rand()%5+1;
    }

    //renvoie true si le joueur artificiel suit, false sinon
    bool Random::suivi()
    {
        int truc = rand()%1;
        if(truc==0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
