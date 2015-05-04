#include <iostream>
#include <string>
#include "Paire.h"

#include "Carte.h"
#include "MainC.h"

using namespace std;

    //retourne 1 si le vecteur de carte correspond a une paire, -1 sinon
    int Paire::identifier(vector<Carte> lesCartes)
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

        if (paire==1)
        {
            retour=1;
        }

        if (retour==1)
        {
            return 1;
        }
        else
        {
            return -1;
        }
    }
