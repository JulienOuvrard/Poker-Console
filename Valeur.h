#ifndef VALEUR_H
#define VALEUR_H

#include <iostream>
#include <string>


class Valeur
	{
    private:
		std::string name_;
		int points_;
		static std::string lesNoms_[14];
	public:
	    Valeur();
		Valeur (std::string nom, int points);
        int getPoints();
		std::string getName();
        static std::string getLeNom(int i);
		static int getNbNoms();
	};

#endif
