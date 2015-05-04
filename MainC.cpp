#include <iostream>
#include <sstream>
#include <string>
#include "math.h"
#include <vector>
#include "MainC.h"

#include "Combinaison.h"
#include "CarteHaute.h"
#include "Paire.h"
#include "DPaire.h"
#include "Brelan.h"
#include "Quinte.h"
#include "Flush.h"
#include "Full.h"
#include "Carre.h"
#include "QuinteF.h"
#include "QuinteFR.h"

#include "VisitorConcret.h"

using namespace std;

    //constructeur par défaut
    MainC::MainC()
    {
        vector<Carte> laMain_;
    }

    //fonction rajoutant la carte passée en parametre dans l'attribut laMain
    void MainC::ajouterCarte(Carte laCarte)
    {
        laMain_.push_back(laCarte);
    }

    //fonction renvoyant la valeur de lamain
    double MainC::combinaison()
    {
        QuinteFR QuinteFR_ = QuinteFR();
        QuinteF QuinteF_ = QuinteF();
        Carre Carre_ = Carre();
        Full Full_ = Full();
        Flush Flush_ = Flush();
        Quinte Quinte_ = Quinte();
        Brelan Brelan_ = Brelan();
        DPaire DPaire_ = DPaire();
        Paire Paire_ = Paire();
        CarteHaute CarteHaute_ = CarteHaute();

        vector<Combinaison*> lesCombinaisons_={&QuinteFR_,&QuinteF_,&Carre_,&Full_,&Flush_,&Quinte_,&Brelan_,&DPaire_,&Paire_,&CarteHaute_};

        int k=0;
        while(lesCombinaisons_.at(k)->identifier(laMain_)==-1)
        {
            k++;
        }
        //TODO : revoir la gestion du visitor car un visitor est créé a chaque appel
        VisitorConcret visitor = VisitorConcret();
        double result=0;
        switch(k)
        {
        case 0:
            result=visitor.calculer(QuinteFR_,laMain_);
            break;
        case 1:
            result=visitor.calculer(QuinteF_,laMain_);
            break;
        case 2:
            result=visitor.calculer(Carre_,laMain_);
            break;
        case 3:
            result=visitor.calculer(Full_,laMain_);
            break;
        case 4:
            result=visitor.calculer(Flush_,laMain_);
            break;
        case 5:
            result=visitor.calculer(Quinte_,laMain_);
            break;
        case 6:
            result=visitor.calculer(Brelan_,laMain_);
            break;
        case 7:
            result=visitor.calculer(DPaire_,laMain_);
            break;
        case 8:
            result=visitor.calculer(Paire_,laMain_);
            break;
        case 9:
            result=visitor.calculer(CarteHaute_,laMain_);
            break;
        }
        return result;
    }

    //fonction affichant chacune des cartes de la main
    void MainC::afficher()
    {
        for (unsigned int i=0;i<laMain_.size();i++)
        {
            laMain_.at(i).afficher();
            cout << endl;
        }
    }

    //accesseur renvoyant la carte a l'index i de l'attribut laMain
    Carte MainC::getCarte(int i)
    {
        return laMain_.at(i);
    }

    //accesseur get de l'attribut laMain
    vector<Carte> MainC::getLaMain()
    {
        return laMain_;
    }
