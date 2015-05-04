#ifndef JEU_H
#define JEU_H

#include <iostream>
#include <vector>
#include <string>

#include "Carte.h"

class Jeu
{
private:
    int nbCarte_;
    std::vector<Carte> leJeu_;
    std::vector<int> numero_;
    int nextCard_;
public:
   Jeu();
   Jeu(int nombreCarte, std::vector<Carte> leJeu );
   void melanger();
   int carteRestante();
   Carte tirerCarte();
   int getNextCard();
};

#endif
