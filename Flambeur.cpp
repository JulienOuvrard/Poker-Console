#include <iostream>
#include <string>
#include "Flambeur.h"
#include <stdlib.h>
#include <time.h>

using namespace std;

    //renvoie la mise tentée par le joueur artificiel
    int Flambeur::mise()
    {
        return 5;
    }

    //renvoie true si le joueur artificiel suit, false sinon
    bool Flambeur::suivi()
    {
        float truc = rand()%(1000);
        if(truc>600)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
