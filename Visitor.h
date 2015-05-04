#ifndef VISITOR_H
#define VISITOR_H

#include <iostream>
#include <string>
#include <vector>

#include "Carte.h"

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

class Visitor
{
    private:


    public:
        double virtual calculer(QuinteFR combi, std::vector<Carte> lesCartes)=0;
        double virtual calculer(QuinteF combi, std::vector<Carte> lesCartes)=0;
        double virtual calculer(Carre combi, std::vector<Carte> lesCartes)=0;
        double virtual calculer(Full combi, std::vector<Carte> lesCartes)=0;
        double virtual calculer(Flush combi, std::vector<Carte> lesCartes)=0;
        double virtual calculer(Quinte combi, std::vector<Carte> lesCartes)=0;
        double virtual calculer(Brelan combi, std::vector<Carte> lesCartes)=0;
        double virtual calculer(DPaire combi, std::vector<Carte> lesCartes)=0;
        double virtual calculer(Paire combi, std::vector<Carte> lesCartes)=0;
        double virtual calculer(CarteHaute combi, std::vector<Carte> lesCartes)=0;


};

#endif
