#include <iostream>
#include <string>
#include "math.h"
#include "VisitorConcret.h"

#include "MainC.h"
using namespace std;

    //fonction renvoyant la valeur de la combinaison quinte flush royale du vecteur de cartes
    double VisitorConcret::calculer(QuinteFR combi, std::vector<Carte> lesCartes)
    {
        double valeurRetour;
        valeurRetour=9*pow(15,5);
        return valeurRetour;
    }

    //fonction renvoyant la valeur de la combinaison quinte flush du vecteur de cartes
    double VisitorConcret::calculer(QuinteF combi, std::vector<Carte> lesCartes)
    {
        unsigned int i=0;
        double valeurRetour=0;
        int valeurs[15]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
        int trefle=0, carreau=0, pic=0, coeur=0;
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
        if (valeurSuite2!=14&&suite2Max>4)
        {
            valeurRetour=8*pow(15,5);
            valeurRetour+=valeurSuite2*pow(15,4);
        }
       return valeurRetour;
    }

    //fonction renvoyant la valeur de la combinaison carre du vecteur de cartes
    double VisitorConcret::calculer(Carre combi, std::vector<Carte> lesCartes)
    {
        unsigned int i=0;
        double valeurRetour=0;
        int valeurs[15]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
        int carreV=0;
        while(i<lesCartes.size())
        {
            valeurs[lesCartes.at(i).getValeur().getPoints()]++;
            i++;
        }
        valeurs[14]=valeurs[1];
        for (i=1; i<=14; i++)
        {
            if (valeurs[i]==4)
            {
                carreV=i;
            }
        }
        valeurRetour=7*pow(15,5);
        valeurRetour+=carreV*pow(15,4);
        int j=14;
        while(valeurs[j]==0 || j==carreV)
        {
            j--;
        }
        valeurRetour+=j*pow(15,3);
        return valeurRetour;
    }

    //fonction renvoyant la valeur de la combinaison full du vecteur de cartes
    double VisitorConcret::calculer(Full combi, std::vector<Carte> lesCartes)
    {
        unsigned int i=0;
        double valeurRetour=0;
        int valeurs[15]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
        int paire=0, paireV=0, paire2V=0, brelan=0, brelanV=0, brelan2V=0;
        while(i<lesCartes.size())
        {
            valeurs[lesCartes.at(i).getValeur().getPoints()]++;
            i++;
        }

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
        if (paire2V>paireV)
        {
            int temp=paire2V;
            paire2V=paireV;
            paireV=temp;
        }
        valeurRetour=6*pow(15,5);
        if (brelan==2)
        {
            if (brelanV>brelan2V)
            {
                int temp=brelanV;
                brelanV=brelan2V;
                brelan2V=temp;
            }
            valeurRetour+=brelan2V*pow(15,4);
            valeurRetour+=brelanV*pow(15,3);

        }
        else
        {
            valeurRetour+=brelanV*pow(15,4);
            valeurRetour+=paireV*pow(15,3);
        }
        return valeurRetour;
    }

    //fonction renvoyant la valeur de la combinaison couleur du vecteur de cartes
    double VisitorConcret::calculer(Flush combi, std::vector<Carte> lesCartes)
    {
        unsigned int i=0;
        int trefle=0, carreau=0, pic=0, coeur=0;
        int valeurs[15]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
        string couleurC;
        double valeurRetour;
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
        valeurRetour=5*pow(15,5);
        valeurRetour+=valeurS[6]*pow(15,4);
        valeurRetour+=valeurS[5]*pow(15,3);
        valeurRetour+=valeurS[4]*pow(15,2);
        valeurRetour+=valeurS[3]*15;
        valeurRetour+=valeurS[2];
        return valeurRetour;
    }

    //fonction renvoyant la valeur de la combinaison quinte du vecteur de cartes
    double VisitorConcret::calculer(Quinte combi, std::vector<Carte> lesCartes)
    {
        unsigned int i=0;
        int valeurs[15]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
        double valeurRetour;
        int suite=0, suiteMax=0, valeurSuite=0;
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
                    valeurSuite=i;
                }
            }
            else
            {
                suite=0;
            }
        }
        if(valeurSuite==1)
        {
            valeurSuite=14;
        }
        valeurRetour=4*pow(15,5);
        valeurRetour+=valeurSuite*pow(15,4);
        return valeurRetour;
    }

    //fonction renvoyant la valeur de la combinaison brelan du vecteur de cartes
    double VisitorConcret::calculer(Brelan combi, std::vector<Carte> lesCartes)
    {
        unsigned int i=0;
        int valeurs[15]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
        double valeurRetour;
        int brelanV=0;
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
                brelanV=i;
            }
        }
        if (brelanV==1)
        {
            brelanV=14;
        }
        valeurRetour=3*pow(15,5);
        valeurRetour+=brelanV*pow(15,4);
        i=0;
        int j=14;
        while (i<2)
        {
            while(valeurs[j]==0 || j==brelanV)
            {
                j--;
            }
            valeurRetour+=j*pow(15,3-i);
            i++;
            j--;
        }
        return valeurRetour;
    }

    //fonction renvoyant la valeur de la combinaison double paire du vecteur de cartes
    double VisitorConcret::calculer(DPaire combi, std::vector<Carte> lesCartes)
    {
        unsigned int i=0;
        int valeurs[15]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
        double valeurRetour;
        int paireV=0, paire2V=0;
        while(i<lesCartes.size())
        {
            valeurs[lesCartes.at(i).getValeur().getPoints()]++;
            i++;
        }
        //valeurs[14]=valeurs[1];
        for (i=1; i<14; i++)
        {
            if (valeurs[i]==2)
            {
                if (paireV!=0)
                {
                    paire2V=i;
                }
                else
                {
                    paireV=i;
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
        if (paireV>paire2V)
        {
            int temp=paireV;
            paireV=paire2V;
            paire2V=temp;
        }
        valeurRetour=2*pow(15,5);
        valeurRetour+=paire2V*pow(15,4);
        valeurRetour+=paireV*pow(15,3);
        int j=14;
        while(valeurs[j]==0 || j==paire2V || j==paireV)
        {
            j--;
        }
        valeurRetour+=j*pow(15,2);
        return valeurRetour;
    }

    //fonction renvoyant la valeur de la combinaison paire du vecteur de cartes
    double VisitorConcret::calculer(Paire combi, std::vector<Carte> lesCartes)
    {
        unsigned int i=0;
        int valeurs[15]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
        double valeurRetour;
        int paireV=0;
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
                paireV=i;
            }
        }
        if (paireV==1)
        {
            paireV=14;
        }
        valeurRetour=1*pow(15,5);
        valeurRetour+=paireV*pow(15,4);
        i=0;
        int j=14;
        while (i<3)
        {
            while(valeurs[j]==0 || j==paireV)
            {
                j--;
            }
            valeurRetour+=j*pow(15,3-i);
            i++;
            j--;
        }
        return valeurRetour;
    }

    //fonction renvoyant la valeur de la combinaison carte haute du vecteur de cartes
    double VisitorConcret::calculer(CarteHaute combi, std::vector<Carte> lesCartes)
    {
        unsigned int i=0;
        int valeurs[15]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
        double valeurRetour=0;
        while(i<lesCartes.size())
        {
            valeurs[lesCartes.at(i).getValeur().getPoints()]++;
            i++;
        }
        valeurs[14]=valeurs[1];
        i=0;
        int j=14;
        while (i<5)
        {
            while(valeurs[j]==0)
            {
                j--;
            }
            valeurRetour+=j*pow(15,4-i);
            i++;
            j--;
        }
        valeurRetour++;
        return valeurRetour;
    }
