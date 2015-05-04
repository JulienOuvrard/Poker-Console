#include <iostream>
#include <string>
#include "Brelan.h"

#include "Carte.h"
#include "MainC.h"

using namespace std;


    //retourne 3 si le vecteur de carte correspond a un brelan, -1 sinon
    int Brelan::identifier(vector<Carte> lesCartes)
    {
        int retour=0;
        unsigned int i=0;
        int valeurs[15]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
        int brelan=0;

        while(i<lesCartes.size())
        {
            valeurs[lesCartes.at(i).getValeur().getPoints()]++;
            i++;
        }

        valeurs[14]=valeurs[1];
        for (i=1; i<14; i++)
        {
            if (valeurs[i]==3)
            {
                brelan++;

            }
        }
        if (brelan>=1)
        {
            retour=3;
        }

        if (retour==3)
        {
            return 3;
        }
        else
        {
            return -1;
        }
    }



