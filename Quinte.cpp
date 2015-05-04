#include <iostream>
#include <string>
#include "Quinte.h"

#include "Carte.h"
#include "MainC.h"

using namespace std;

    //retourne 4 si le vecteur de carte correspond a une quinte, -1 sinon
    int Quinte::identifier(vector<Carte> lesCartes)
    {
        int retour=0;
        unsigned int i=0;
        int valeurs[15]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
        int suite=0;
        int suiteMax=0;

        while(i<lesCartes.size())
        {
            valeurs[lesCartes.at(i).getValeur().getPoints()]++;
            i++;
        }

        valeurs[14]=valeurs[1];
        for (i=1; i<14; i++)
        {
            if (valeurs[i]!=0)
            {
                suite++;
                if (suite>=suiteMax)
                {
                    suiteMax=suite;
                }
            }
            else
            {
                suite=0;
            }
        }
        if (valeurs[1]!=0)
        {
            suite++;
            if (suite>=suiteMax)
            {
                suiteMax=suite;
            }
        }
        else
        {
            suite=0;
        }

        if (suiteMax>=5)
        {
            retour=4;
        }

        if (retour==4)
        {
            return 4;
        }
        else
        {
            return -1;
        }
    }


