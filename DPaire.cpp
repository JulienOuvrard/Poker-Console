#include <iostream>
#include <string>
#include "DPaire.h"

#include "Carte.h"
#include "MainC.h"

using namespace std;

    //retourne 2 si le vecteur de carte correspond a une double paire, -1 sinon
    int DPaire::identifier(vector<Carte> lesCartes)
    {
        int retour=0;
        unsigned int i=0;
        int valeurs[15]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
        int paire=0;

        while(i<lesCartes.size())
        {
            valeurs[lesCartes.at(i).getValeur().getPoints()]++;
            i++;
        }

        valeurs[14]=valeurs[1];
        for (i=1; i<14; i++)
        {
            if (valeurs[i]==2)
            {
                paire++;
            }
        }

        if (paire>=2)
        {
            retour=2;
        }

        if (retour==2)
        {
            return 2;
        }
        else
        {
            return -1;
        }
    }



