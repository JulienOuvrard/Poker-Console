#ifndef MAINC_H
#define MAINC_H

#include <iostream>
#include <vector>
#include <array>
#include <string>

#include "Carte.h"
#include "Combinaison.h"

class MainC
{
private:
    std::vector<Carte> laMain_;
public:
    MainC();
    void ajouterCarte(Carte laCarte);
    double combinaison();
    void afficher();
    Carte getCarte(int);
    std::vector<Carte> getLaMain();
};

#endif
