#include <iostream>
#include <string>
#include <vector>
#include <typeinfo>
#include "Partie.h"
#include "Humain.h"

using namespace std;

    //constructeur par défaut
    Partie::Partie()
    {
        vector<Joueur> lesJoueurs_;
        vector<Carte> jeuCommun_;
        leJeu_=Jeu();
        pot_=0;
        joueurEnCours_=0;
        dealer_=0;
        blind_=1;

        //CRETATION DU JEU DE CARTES
        vector<Couleur> lesCouleurs;
        for (int k=0; k<Couleur::getNbNoms();k++)
        {
            lesCouleurs.push_back(Couleur(Couleur::getLeNom(k)));
        }

        vector<Valeur> lesValeurs;
        for (int k=1; k<Valeur::getNbNoms();k++)
        {
            lesValeurs.push_back(Valeur(Valeur::getLeNom(k),k));
        }

        vector<Carte> lesCartes;
        for(unsigned int i=0;i<lesCouleurs.size();i++)
        {
            for (unsigned int j=0;j<lesValeurs.size();j++)
            {
                Carte carte(lesCouleurs.at(i),lesValeurs.at(j));
                lesCartes.push_back(carte);
            }
        }


        leJeu_ = Jeu(52, lesCartes);
    }

    //fonction reinitialisant les mains de chaque joueur et leur distribuant chacun deux cartes
    void Partie::distribuer()
    {
        for(unsigned i=0; i<lesJoueurs_.size(); i++)
        {
            lesJoueurs_.at(i).resetMain();
            MainC temp;
            temp=lesJoueurs_.at(i).getLaMain();
            temp.ajouterCarte(leJeu_.tirerCarte());
            temp.ajouterCarte(leJeu_.tirerCarte());
            lesJoueurs_.at(i).setLaMain(temp);
        }
    }

    //fonction renvoyant l'indice dans le vecteur lesJoueurs du joueur encore en jeu ayant la plus grosse combinaison
    int Partie::gagnant()
    {
        int j=0;
        double mainMax=0;
        for(unsigned i=0; i<lesJoueurs_.size(); i++)
        {
            if (i==0)
            {
                mainMax=getJoueur(i).combinaison(getJeuCommun());
            }
            else if (getJoueur(i).combinaison(getJeuCommun())>mainMax)
            {
                mainMax=getJoueur(i).combinaison(getJeuCommun());
                j=i;
            }
        }
        return j;
    }

    //fonction reinitialisant les mises en cours de chaque joueur et les ajoutant au pot
    void Partie::reunirMises()
    {
        for(unsigned i=0; i<lesJoueurs_.size(); i++)
        {
            pot_+=lesJoueurs_.at(i).getMiseEnCours();
            lesJoueurs_.at(i).resetMiseEnCours();
        }
        afficherPot();
    }

    //fonction gerant le tirage et l'affichage du flop
    void Partie::flop()
    {
        jeuCommun_.push_back(leJeu_.tirerCarte());
        jeuCommun_.push_back(leJeu_.tirerCarte());
        jeuCommun_.push_back(leJeu_.tirerCarte());

        cout<<"Flop : ";
        for(unsigned i=0; i<jeuCommun_.size();i++)
        {
            jeuCommun_.at(i).afficher();
            cout<< " -- ";
        }
        cout<<endl;
    }

    //fonction gerant le tirage et l'affichage du turc
    void Partie::turn()
    {
        jeuCommun_.push_back(leJeu_.tirerCarte());
        cout<<"Turn : ";
        jeuCommun_.at(jeuCommun_.size()-1).afficher();
        cout<<endl;
    }

    //fonction gerant le tirage et l'affichage de la river
    void Partie::river()
    {
        jeuCommun_.push_back(leJeu_.tirerCarte());
        cout<<"River : ";
        jeuCommun_.at(jeuCommun_.size()-1).afficher();
        cout<<endl;
    }

    //fonction gerant l'affichage des cartes de joueurs en fin de partie
    void Partie::showdown()
    {
        for(unsigned i=0; i<lesJoueurs_.size(); i++)
        {
            lesJoueurs_.at(i).showdown(i);
        }
    }

    //accesseur get de l'attribut dealer
    int Partie::getDealer()
    {
        return dealer_;
    }

    //fonction faisant tourner le jeton dealer
    void Partie::tournerDealer()
    {
        dealer_++;
        unsigned int dealer=dealer_;
        if (dealer==lesJoueurs_.size())
        {
            dealer_=0;
        }
        while(lesJoueurs_.at(dealer_).getEtat()==lesJoueurs_.at(dealer_).getLooser())
        {
            dealer_++;
            unsigned int dealer=dealer_;
            if (dealer==lesJoueurs_.size())
            {
                dealer_=0;
            }
        }
    }

    //accesseur set de l'attribut leJeu
    void Partie::setJeu(Jeu leJeu)
    {
        leJeu_=leJeu;
    }

    //fonction ajoutant un joueur a l'attribut lesJoueurs
    void Partie::ajouterJoueur(Joueur leJoueur)
    {
        lesJoueurs_.push_back(leJoueur);
    }

    //fonction affichant la somme du pot
    void Partie::afficherPot()
    {
        cout << "Le pot est desormais de " << pot_<<endl;
    }

    //fonction faisant miser les blinds
    void Partie::blinds()
    {
        unsigned int i=(getDealer()+1)%lesJoueurs_.size();
        while(lesJoueurs_.at(i).getEtat()==lesJoueurs_.at(i).getLooser())
        {
            i++;
            if (i==lesJoueurs_.size())
            {
                i=0;
            }
        }
        lesJoueurs_.at(i).miser(blind_);
        i++;
        if (i==lesJoueurs_.size())
        {
            i=0;
        }
        while(lesJoueurs_.at(i).getEtat()==lesJoueurs_.at(i).getLooser())
        {
            i++;
            if (i==lesJoueurs_.size())
            {
                i=0;
            }
        }
        lesJoueurs_.at(i).miser(blind_*2);
    }

    //accesseur renvoyant le joueur a l'index i de l'attribut lesJoueurs
    Joueur Partie::getJoueur(int i)
    {
        return lesJoueurs_.at(i);
    }

    //accesseur get de l'attribut jeuCommun
    vector<Carte> Partie::getJeuCommun()
    {
        return jeuCommun_;
    }

    //fonction renvoyant true si la mise est valide (supérieure ou egale a celle des autres joueurs)
    bool Partie::validMise(int mise)
    {
        for (unsigned int i=0;i<lesJoueurs_.size();i++)
        {
            if (lesJoueurs_.at(i).getEtat()==lesJoueurs_.at(i).getEnJeu())
            {
                if (mise<lesJoueurs_.at(i).getMiseEnCours())
                {
                    return false;
                }
            }
        }
        return true;
    }

    //fonction renvoyant le nombre de joueurs encore en jeu
    int Partie::joueursEnJeu()
    {
        int i=0;
        for (unsigned int j=0;j<lesJoueurs_.size();j++)
        {
            if (lesJoueurs_.at(j).getEtat()==lesJoueurs_.at(j).getEnJeu())
            {
                i++;
            }
        }
        return i;
    }

    //fonction principale gerant le déroulement du jeu
    void Partie::commencer()
    {
        do
        {
            for (unsigned int i=0;i<lesJoueurs_.size();i++)
            {
                if(lesJoueurs_.at(i).getEtat()==lesJoueurs_.at(i).getCouche())
                {
                    lesJoueurs_.at(i).setEtat(lesJoueurs_.at(i).getEnJeu());
                }
            }
            cout<< "Le dealer est : "<<lesJoueurs_.at(dealer_).getName()<<endl;
            leJeu_.melanger();
            distribuer();
            cout << "Votre Main :"<<endl;
            lesJoueurs_.at(4).getLaMain().afficher();
            blinds();
            int i=(getDealer()+3)%lesJoueurs_.size();
            tourDeMise(i);
            if (joueursEnJeu()!=1)
            {
                flop();
                i=(getDealer()+1)%lesJoueurs_.size();
                tourDeMise(i);
                if (joueursEnJeu()!=1)
                {
                    turn();
                    tourDeMise(i);
                    if (joueursEnJeu()!=1)
                    {
                        river();
                        tourDeMise(i);
                        if (joueursEnJeu()!=1)
                        {
                            showdown();
                            int winner=gagnant();
                            cout << lesJoueurs_.at(winner).getName() << " remporte la victoire" << endl;
                            lesJoueurs_.at(winner).ajouterJetons(pot_);
                        }
                    }
                }
            }
            affichageJetons();
            for (unsigned int i=0;i<lesJoueurs_.size();i++)
            {
                if (lesJoueurs_.at(i).getJetons()==0)
                {
                    lesJoueurs_.at(i).setEtat(lesJoueurs_.at(i).getLooser());
                }
            }
            jeuCommun_.clear();
            pot_=0;
            tournerDealer();
        }
        while(nbLooser()<lesJoueurs_.size()-1);

    }

    //fonction gerant les actions d'un tour de mise (=2 tours de table)
    void Partie::tourDeMise(int i)
    {
        bool first=true;
        bool firstTour=true;
        while(!finTour()||first)
        {
            first=false;
            while(lesJoueurs_.at(i).getEtat()!=lesJoueurs_.at(i).getEnJeu())
            {
                i++;
                unsigned int j=i;
                if (j==lesJoueurs_.size())
                {
                    i=0;
                }
            }
            if(firstTour)
            {
                lesJoueurs_.at(i).miser(lesJoueurs_.at(i).getStrategie()->mise());
            }
            else
            {
                lesJoueurs_.at(i).suivre(lesJoueurs_.at(i).getStrategie()->suivi());
            }
            i++;
            unsigned int j=i;
            if (j==lesJoueurs_.size())
            {
                i=0;
                firstTour=false;
            }
        }
        reunirMises();
        changerStrat();
    }

    //fonction appelée lorsqu'il ne reste plus qu'un seul joueur en jeu
    void Partie::lastSurvivor()
    {
        int j=0;
        while(lesJoueurs_.at(j).getEtat()!=lesJoueurs_.at(j).getEnJeu())
        {
            j++;
        }
        cout << "Last Survivor : "<< lesJoueurs_.at(j).getName()<<endl;
        int jetons=0;
        for (unsigned int i=0;i<lesJoueurs_.size();i++)
        {
            jetons+=lesJoueurs_.at(i).getMiseEnCours();
            lesJoueurs_.at(i).resetMiseEnCours();
        }
        jetons+=pot_;
        lesJoueurs_.at(j).ajouterJetons(jetons);
    }

    //fonction renvoyant true si les joueurs encore en jeu ont la meme mise en cours, false sinon
    bool Partie::finTour()
    {
        int j=0;
        while(lesJoueurs_.at(j).getEtat()!=lesJoueurs_.at(j).getEnJeu())
        {
            j++;
        }
        int mise=lesJoueurs_.at(j).getMiseEnCours();
        for (unsigned int i=j+1;i<lesJoueurs_.size();i++)
        {
            if (lesJoueurs_.at(i).getEtat()==lesJoueurs_.at(i).getEnJeu())
            {
                if (mise!=lesJoueurs_.at(i).getMiseEnCours())
                {
                    return false;
                }
            }
        }
        return true;
    }

    //fonction renvoyant le maximum des mises des joueurs encore en jeu
    int Partie::getMiseMax()
    {
        int j=0;
        while(lesJoueurs_.at(j).getEtat()!=lesJoueurs_.at(j).getEnJeu())
        {
            j++;
        }
        int mise=lesJoueurs_.at(j).getMiseEnCours();
        for (unsigned int i=j+1;i<lesJoueurs_.size();i++)
        {
            if (lesJoueurs_.at(i).getEtat()==lesJoueurs_.at(i).getEnJeu())
            {
                if (mise<lesJoueurs_.at(i).getMiseEnCours())
                {
                    mise=lesJoueurs_.at(i).getMiseEnCours();
                }
            }
        }
        return mise;
    }

    //retourne le nombre de joueurs ayant deja perdu la partie
    unsigned int Partie::nbLooser()
    {
        unsigned int j=0;
        while(lesJoueurs_.at(j).getEtat()==lesJoueurs_.at(j).getLooser())
        {
            j++;
        }
        return j;
    }

    //fonction affichant chaque joueur
    void Partie::affichageJetons()
    {
        for (unsigned int i=0;i<lesJoueurs_.size();i++)
        {
            lesJoueurs_.at(i).affichage(i);
        }
    }

    //fonction faisant changer de strategie chaque joueur artificiels
    void Partie::changerStrat()
    {
        for (unsigned int i=0;i<lesJoueurs_.size();i++)
        {
            string type=typeid((*(lesJoueurs_.at(i).getStrategie()))).name();
            if (type.substr(1)!="Humain")
            {
                lesJoueurs_.at(i).changerStrategie();
            }

        }
    }
