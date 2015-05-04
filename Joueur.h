#ifndef JOUEUR_H
#define JOUEUR_H

#include <iostream>
#include <vector>
#include <array>
#include <string>

#include "MainC.h"
#include "State.h"
class State;

#include "Strategie.h"
class Strategie;

#include "Partie.h"
class Partie;

class Joueur
{
private:
    bool encoreEnJeu_;
    int jetons_;
    int miseEnCours_;
    std::string nom_;
    MainC laMain_;
    State *etat_;
    State *enJeu_;
    State *couche_;
    State *looser_;
    Strategie *strategie_;
    Partie *laPartie_;
public:
    Joueur();
    Joueur(std::string nom, int jetons, Partie *laPartie);
    MainC getLaMain();
    int getJetons();
    void setLaMain(MainC);
    int miser(int mise);
    int getMiseEnCours();
    Carte getCarte(int);
    std::string getName();
    void setEtat(State *etat);
    State* getEtat();
    State* getEnJeu();
    State* getCouche();
    State* getLooser();
    Strategie* getStrategie();
    void setStrategie(Strategie *strat);
    void ajouterJetons(int jetons);
    void resetMiseEnCours();
    int suivre(bool);
    Partie* getLaPartie();
    void resetMain();
    void changerStrategie();
    void affichage(int);
    double combinaison(std::vector<Carte> jeuCommun);
    void showdown(int);
};

#endif
