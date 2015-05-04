#include <iostream>
#include <string>
#include "Carte.h"


using namespace std;

        //constructeur par défaut
        Carte::Carte()
        {
            couleur_=Couleur();
            valeur_=Valeur();
        }

        //constructeur avec une couleur et une valeur
         Carte::Carte (Couleur coul, Valeur val)
        {
            couleur_=coul;
            valeur_=val;
        }

        //affichage console d'une carte
        void Carte::afficher()
        {
            cout<<valeur_.getName()+" de "+couleur_.getName();
        }

        //accesseur get de l'attribut valeur
        Valeur Carte::getValeur()
        {
            return valeur_;
        }

        //accesseur get de l'attribut couleur
        Couleur Carte::getCouleur()
        {
            return couleur_;
        }

