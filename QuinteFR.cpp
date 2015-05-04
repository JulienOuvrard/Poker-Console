#include <iostream>
#include <string>
#include "QuinteFR.h"

#include "Carte.h"
#include "MainC.h"

using namespace std;

    //retourne 9 si le vecteur de carte correspond a une quinte flush royale, -1 sinon
    int QuinteFR::identifier(vector<Carte> lesCartes)
    {
        int retour=0;
        unsigned int i=0;
        int trefle=0, carreau=0, coeur=0, pic=0;
        int valeurs[15]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
        bool couleur=false;
        int suite=0;
        int suiteMax=0;
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
        if (trefle>=5 || carreau>=5 || pic>=5 || coeur>=5)
        {
            couleur=true;
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
        if (suiteMax>=5 && couleur)
        {
            MainC tempMain=MainC();
            for(unsigned int i=0; i<lesCartes.size();i++)
            {
                if (lesCartes.at(i).getCouleur().getName()==couleurC)
                {
                    tempMain.ajouterCarte(lesCartes.at(i));
                }
            }
            i=0;
            int valeurs2[14]={0,0,0,0,0,0,0,0,0,0,0,0,0,0};
            while(i<tempMain.getLaMain().size())
            {
                valeurs2[tempMain.getLaMain().at(i).getValeur().getPoints()]++;
                i++;
            }
            int suite2=0;
            int suite2Max=0;
            int valeurSuite2=0;
            for (i=1; i<14; i++)
            {
                if (valeurs2[i]!=0)
                {
                    suite2++;
                    if (suite2>=suite2Max)
                    {
                        suite2Max=suite2;
                        valeurSuite2=i;
                    }
                }
                else
                {
                    suite2=0;
                }
            }
            if (valeurs2[1]!=0)
            {
                suite2++;
                if (suite2>=suite2Max)
                {
                    suite2Max=suite2;
                    valeurSuite2=i;
                }
            }
            if (valeurSuite2==14&&suite2Max>4)
           {
               retour=9;
           }
        }
        if (retour==9)
        {
            return 9;
        }
        else
        {
            return -1;
        }
    }


