#include <iostream>
#include <string>
#include "State.h"


using namespace std;

    //constructeur initialisant l'attribut leJoueur
    State::State(Joueur *leJoueur)
    {
        leJoueur_=leJoueur;
    }
