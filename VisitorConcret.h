#ifndef VISITORCONCRET_H
#define VISITORCONCRET_H

#include <iostream>
#include <string>
#include <vector>

#include "Carte.h"
#include "Visitor.h"

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

class VisitorConcret : public Visitor
{
    private:


    public:
        double calculer(QuinteFR combi, std::vector<Carte> lesCartes);
        double calculer(QuinteF combi, std::vector<Carte> lesCartes);
        double calculer(Carre combi, std::vector<Carte> lesCartes);
        double calculer(Full combi, std::vector<Carte> lesCartes);
        double calculer(Flush combi, std::vector<Carte> lesCartes);
        double calculer(Quinte combi, std::vector<Carte> lesCartes);
        double calculer(Brelan combi, std::vector<Carte> lesCartes);
        double calculer(DPaire combi, std::vector<Carte> lesCartes);
        double calculer(Paire combi, std::vector<Carte> lesCartes);
        double calculer(CarteHaute combi, std::vector<Carte> lesCartes);

};

#endif
