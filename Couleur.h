#ifndef COULEUR_H
#define COULEUR_H

#include <iostream>
#include <string>


class Couleur
	{
    private:
		std::string name_;
		static std::string lesNoms_[4];
	public:
	    Couleur();
		Couleur (std::string nom);

		std::string getName();
		static std::string getLeNom(int i);
		static int getNbNoms();


	};

#endif
