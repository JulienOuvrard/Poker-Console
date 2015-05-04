#include <iostream>
#include <string>
#include "Flush.h"

#include "Carte.h"
#include "MainC.h"

using namespace std;

    //retourne 5 si le vecteur de carte correspond a une couleur, -1 sinon
    int Flush::identifier(vector<Carte> lesCartes)
    {
        int retour=0;
        unsigned int i=0;
        int trefle=0, carreau=0, coeur=0, pic=0;
        int valeurs[15]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
        string couleurC;

        while(i<lesCartes.size())
        {
            if(lesCartes.at(i).getCouleur().getName()=="trefle")
            {
                trefle++;
            }
            if(lesCartes.at(i).getCouleur().getName()=="carreau")
            {
                carreau++;
            }
            if(lesCartes.at(i).getCouleur().getName()=="pic")
            {
                pic++;
            }
            if(lesCartes.at(i).getCouleur().getName()=="coeur")
            {
                coeur++;
            }
            valeurs[lesCartes.at(i).getValeur().getPoints()]++;
            i++;
        }
        valeurs[14]=valeurs[1];
        if (trefle>=5 || carreau>=5 || pic>=5 || coeur>=5)
        {
            if (trefle>=5)
            {
                couleurC="trefle";
            }
            if (carreau>=5)
            {
                couleurC="carreau";
            }
            if (pic>=5)
            {
                couleurC="pic";
            }
            if (coeur>=5)
            {
                couleurC="coeur";
            }

            int valeurS[]={0,0,0,0,0,0,0};
            for (unsigned int i=0; i<lesCartes.size();i++)
            {
                if (lesCartes.at(i).getCouleur().getName()==couleurC)
                {
                    if (lesCartes.at(i).getValeur().getPoints()==1)
                    {
                        valeurS[i]=14;
                    }
                    else
                    {
                        valeurS[i]=lesCartes.at(i).getValeur().getPoints();
                    }
                }
            }

            for (unsigned i=0; i<6;i++)
            {
                for (unsigned j=0;j<7;j++)
                {
                    if (valeurS[j]>valeurS[j+1])
                    {
                        int temp=valeurS[j];
                        valeurS[j]=valeurS[j+1];
                        valeurS[j+1]=temp;
                    }
                }
            }
            retour=5;
        }
        if (retour==5)
        {
            return 5;
        }
        else
        {
            return -1;
        }
    }
