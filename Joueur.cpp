#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include "Joueur.h"
#include "EnJeu.h"
#include "Couche.h"
#include "Looser.h"
#include "Poulette.h"
#include "Flambeur.h"
#include "Random.h"

using namespace std;


    //constructeur par défaut
    Joueur::Joueur()
    {
        nom_="Unnamed";
        encoreEnJeu_=true;
        jetons_=0;
        miseEnCours_=0;
        laMain_=MainC();

    }

    //constructeur avec un nom, un nombre de jetons et un pointeur vers la partie a laquelle il va participer
    Joueur::Joueur(string nom, int jetons, Partie *laPartie)
    {
        nom_=nom;
        encoreEnJeu_=true;
        jetons_=jetons;
        miseEnCours_=0;
        laMain_=MainC();
        enJeu_= new EnJeu(this);
        couche_= new Couche(this);
        looser_= new Looser(this);
        etat_=couche_;
        laPartie_=laPartie;
        strategie_=new Flambeur(this);
    }

    //accesseur get de l'attribut jetons
    int Joueur::getJetons()
    {

        return jetons_;
    }

    //accesseur get de l'attribut laMain
    MainC Joueur::getLaMain()
    {
        return laMain_;
    }

    //accessseur set de l'attribut laMain
    void Joueur::setLaMain(MainC laMain)
    {
        laMain_=laMain;
    }

    //fonction gerant le gain de jetons par le joueur
    void Joueur::ajouterJetons(int jetons)
    {
        cout << nom_ << " gagne " << jetons << " jetons."<<endl;
        jetons_+=jetons;
    }

    //fonction reinitialisant la mise en cours (fin du tour de mise)
    void Joueur::resetMiseEnCours()
    {
        miseEnCours_=0;
    }

    //fonction gerant la mise de jetons (nombre passe en parametre) par le joueur
    int Joueur::miser(int mise)
    {
        if(laPartie_->validMise(mise+miseEnCours_))
        {
            if (mise>jetons_)
            {
                if (jetons_!=0)
                {
                    cout << nom_ << " doit miser " << mise << " mais n'a que " << jetons_ << " et fait all in" << endl;
                    int temp=jetons_;
                    miseEnCours_+=jetons_;
                    jetons_-=jetons_;
                    return temp;
                }
                else
                {
                    return 0;
                }
            }
            else
            {
                cout << nom_ << " mise " << mise << endl;
                jetons_-=mise;
                miseEnCours_+=mise;
                cout << "Mise du Joueur : "<<miseEnCours_<<endl;
                return mise;
            }
        }
        else
        {
            setEtat(getCouche());
            return 0;
        }
    }

    //accesseur get de l'attribut miseEnCours
    int Joueur::getMiseEnCours()
    {
        return miseEnCours_;
    }

    //accesseur renvoyant la carte a l'indice j de l'attribut laMain
    Carte Joueur::getCarte(int j)
    {
        return laMain_.getCarte(j);
    }

    //accesseur get de l'attribut nom
    string Joueur::getName()
    {
        return nom_;
    }

    //accesseur set de l'attribut etat
    //se charge egalement de l'arrichage du changement d'état
    void Joueur::setEtat(State *etat)
    {
        etat_=etat;
        if(etat==enJeu_)
        {
            cout << nom_ << " enter the game" << endl;
        }
        if(etat==couche_)
        {
            cout << nom_ << " fold" << endl;
            cout << "Joueur(s) en jeu : " << laPartie_->joueursEnJeu() << endl;
            if (laPartie_->joueursEnJeu()==1)
            {
                laPartie_->lastSurvivor();
            }
        }
        if(etat==looser_)
        {
            cout << nom_ << " leave the game" << endl;
        }
    }

    //accesseur get de l'attribut etat
    State* Joueur::getEtat()
    {
        return etat_;
    }

    //accesseur get de l'attribut enJeu
    State* Joueur::getEnJeu()
    {
        return enJeu_;
    }

    //accesseur get de l'attribut couche
    State* Joueur::getCouche()
    {
        return couche_;
    }

    //accesseur get de l'attribut looser
    State* Joueur::getLooser()
    {
        return looser_;
    }

    //accesseur get de l'attribut strategie
    Strategie* Joueur::getStrategie()
    {
         return strategie_;
    }

    //accessseur set de l'attribut strategie
    void Joueur::setStrategie(Strategie *strat)
    {
        strategie_=strat;
    }

    //fonction gerant le suivi (ou non suivant le parametre) du joueur
    int Joueur::suivre(bool suivi)
    {
        if(suivi)
        {
            int miseMax=laPartie_->getMiseMax()-miseEnCours_;
            if (miseMax>jetons_)
            {
                cout << nom_ << " doit suivre a " << miseMax << " mais n'a que " << jetons_ <<endl;
                int temp=jetons_;
                jetons_=0;
                miseEnCours_+=temp;
                return temp;
            }
            else
            {
                cout << nom_ << " a suivi avec " << miseMax << endl;
                jetons_-=miseMax;
                miseEnCours_+=miseMax;
                cout << "Mise du Joueur : "<<miseEnCours_<<endl;
                return miseMax;
            }
        }
        else
        {
            setEtat(getCouche());
        }
        return 0;
    }

    //accesseur get de l'attribut laPartie
    Partie* Joueur::getLaPartie()
    {
        return laPartie_;
    }

    //fonction reinitialisant l'attribut laMain
    void Joueur::resetMain()
    {
        laMain_= MainC();
    }

    //fonction servant a rendre aleatoire les strategies des joueurs artificiels
    //a deplacer vers les strategies
    void Joueur::changerStrategie()
    {
        float truc = rand()%(1000);
        Strategie *strat=strategie_;
        if(truc>900)
        {
            strat=new Poulette(this);
        }
        else if(truc>800)
        {
            strat=new Flambeur(this);
        }
        else if(truc>700)
        {
            strat=new Random(this);
        }
        setStrategie(strat);
    }

    //affichage de l'état du joueur
    void Joueur::affichage(int i)
    {
        etat_->affichage(i);
    }

    //fonction rassemblant les cartes du joueur avec le jeuCommin afin de calculer la valeur de sa main
    double Joueur::combinaison(vector<Carte> jeuCommun)
    {
        MainC testMain;
        testMain=getLaMain();
        for (unsigned int j=0;j<jeuCommun.size();j++)
        {
            testMain.ajouterCarte(jeuCommun.at(j));
        }
        return etat_->combinaison(testMain);
    }

    //affichage du joueur lors du showdown
    void Joueur::showdown(int i)
    {
        etat_->showdown(i);
    }

