#include <iostream>
#include <string>
#include "Full.h"

#include "Carte.h"
#include "MainC.h"

using namespace std;

    //retourne 6 si le vecteur de carte correspond a un full, -1 sinon
    int Full::identifier(vector<Carte> lesCartes)
    {
        int retour=0;
        unsigned int i=0;
        int valeurs[15]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
        int paire=0;
        int brelan=0;
        int brelanV=0;
        int brelan2V;
        int paireV=0;
        int paire2V;

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
                if (paireV!=0)
                {
                    paire2V=i;
                }
                else
                {
                    paireV=i;
                }
            }
            if (valeurs[i]==3)
            {
                brelan++;
                if (brelanV!=0)
                {
                    brelan2V=i;
                }
                else
                {
                    brelanV=i;
                }

            }
        }
        if (paireV==1)
        {
            paireV=14;
        }
        if (paire2V==1)
        {
            paire2V=14;
        }
        if (brelanV==1)
        {
            brelanV=14;
        }
        if (brelan2V==1)
        {
            brelan2V=14;
        }

        if ((paire>=1 && brelan==1) || brelan==2)
        {
            retour=6;
        }
        if (retour==6)
        {
            return 6;
        }
        else
        {
            return -1;
        }
    }

