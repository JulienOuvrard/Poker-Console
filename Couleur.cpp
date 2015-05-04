#include <iostream>
#include <string>
#include "Couleur.h"

using namespace std;

        //constructeur par défaut
        Couleur::Couleur()
        {
            name_="";
        }

        //constructeur avec un nom
		Couleur::Couleur (string nom)
		{
			name_=nom;
		}

        //accesseur get de l'attribut name
		string Couleur::getName()
		{
			return name_;
		}

        //accesseur statique du nombre de couleurs
		int Couleur::getNbNoms()
		{
		    return 4;
		}

        //fonction statique renvoyant le nom de la couleur a l'index i de l'attribut statique lesNoms
		string Couleur::getLeNom(int i)
		{
		    return lesNoms_[i];
		}

        //definition de l'attribut statique lesNoms
        string Couleur::lesNoms_[]={"trefle", "coeur", "carreau", "pic"};
