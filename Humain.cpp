#include <iostream>
#include <string>
#include "Humain.h"


using namespace std;

    //fonction chargée de demande a l'utilisateur son choix lors du 1er tour de mise
    //et renvoyant la mise qu'il souhaite faire
    int Humain::mise()
    {
        int choix;
        int mise;
        do
        {
            cout<<"Que choisissez vous?"<<endl;
            cout<<"1 : Suivre"<<endl;
            cout<<"2 : Relancer"<<endl;
            cout<<"3 : Se coucher"<<endl;
            cin>>choix;
        }
        while(choix!=1&&choix!=2&&choix!=3);
        switch(choix)
        {
        case(1):
            {
                int miseMa=leJoueur_->getLaPartie()->getMiseMax()-leJoueur_->getMiseEnCours();
                if (miseMa>leJoueur_->getJetons())
                {
                    //cout << leJoueur_->getName() << " doit miser " << miseMa << " mais n'a que " << leJoueur_->getJetons() <<endl;
                    mise=leJoueur_->getJetons();
                   // leJoueur_->getJetons()=0;
                    //miseEnCours_+=mise;
                }
                else
                {
                    //cout << leJoueur_->getName() << " a suivi avec " << miseMa << endl;
                    //leJoueur_->getJetons()-=miseMa;
                   // miseEnCours_+=miseMa;
                    //cout << "Mise du Joueur : "<<leJoueur_->getMiseEnCours()<<endl;
                    mise=miseMa-leJoueur_->getLaPartie()->getJoueur(4).getMiseEnCours();
                }
            }
            break;
        case(2):
            do
            {
                cout<<"Combien voulez vous miser ? ("<< leJoueur_->getLaPartie()->getJoueur(4).getJetons() << " jetons)" << endl;
                cin>>mise;
            }
            while(mise<leJoueur_->getLaPartie()->getMiseMax()-leJoueur_->getMiseEnCours()||mise>leJoueur_->getLaPartie()->getJoueur(4).getJetons());

            break;
        case(3):
            //leJoueur_->setEtat(leJoueur_->getCouche());
            mise =-1;
            break;
        }
        return mise;
    }

    //fonction chargée de demande a l'utilisateur son choix lors du 2eme tour de mise
    //renvoyant true si il suit, false sinon
    bool Humain::suivi()
    {
        int choix;
        do
        {
            cout<<"Que choisissez vous?"<<endl;
            cout<<"1 : Suivre"<<endl;
            cout<<"2 : Se Coucher"<<endl;
            cin>>choix;
        }
        while(choix!=1&&choix!=2);
        switch(choix)
        {
        case(1):
            return true;
            break;
        case(2):
            return false;
            break;
        }
        return true;
    }
