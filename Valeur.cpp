#include <iostream>
#include <string>
#include "Valeur.h"


using namespace std;

        //constructeur par défaut
        Valeur::Valeur()
        {
            name_="";
            points_=0;
        }

        //constructeur avec un nom et un nombre de points
		Valeur::Valeur (string nom, int points)
		{
			name_=nom;
			points_=points;
		}

        //accesseur get de l'attribut name
		string Valeur::getName()
		{
			return name_;
		}

        //accesseur get de l'attribut points
		int Valeur::getPoints()
		{
		    return points_;
		}

        //accesseur statique du nombre de valeurs
		int Valeur::getNbNoms()
		{
		    return 14;
		}

        //accesseur statique renvoyant le nom de la valeur a l'indice i de l'attribut lesNoms
		string Valeur::getLeNom(int i)
		{
		    return lesNoms_[i];
		}

        //attribut statique
        string Valeur::lesNoms_[]={"", "as", "deux", "trois", "quatre", "cinq", "six", "sept", "huit", "neuf", "dix", "valet", "dame", "roi"};

