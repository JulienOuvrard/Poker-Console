#include <iostream>
#include <string>
#include "Poulette.h"
#include <stdlib.h>
#include <time.h>


using namespace std;

    //renvoie la mise tentée par le joueur artificiel
    int Poulette::mise()
    {
        return 1;
    }

    //renvoie true si le joueur artificiel suit, false sinon
    bool Poulette::suivi()
    {
        float truc = rand()%(1000);
        if(truc>800)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
