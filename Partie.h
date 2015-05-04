#ifndef PARTIE_H
#define PARTIE_H

#include <iostream>
#include <vector>
#include <array>
#include <string>

#include "Joueur.h"
class Joueur;
#include "Jeu.h"

class Partie
{
private:
    std::vector<Joueur> lesJoueurs_;
    std::vector<Carte> jeuCommun_;
    int dealer_;
    Jeu leJeu_;
    int pot_;
    int joueurEnCours_;
    int blind_;
public:
    //static Partie *partie_;
    Partie();
    void distribuer();
    int gagnant();
    void reunirMises();
    void flop();
    void turn();
    void river();
    void showdown();
    int getDealer();
    void tournerDealer();
    void setJeu(Jeu);
    void ajouterJoueur(Joueur);
    void blinds();
    Joueur getJoueur(int);
    std::vector<Carte> getJeuCommun();
    void commencer();
    void afficherPot();
    bool validMise(int mise);
    int joueursEnJeu();
    void lastSurvivor();
    bool finTour();
    void tourDeMise(int i);
    int getMiseMax();
    unsigned int nbLooser();
    void affichageJetons();
    void changerStrat();
};

#endif
