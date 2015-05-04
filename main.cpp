#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include "Partie.h"
#include "Humain.h"

using namespace std;


/*cette fonction sert a rendre lisible humainement une valeur de combinaison
la fonction affiche 6 nombres
le 1er indique la combinaison (9 QFR, 8 QF, etc.)
les autres servent a comparer deux combinaisons identiques
exemple une paire de roi avec neuf sept quatre donne : 1 (paire) 13 (de roi) 9 (avec un neuf) 7 (un sept) 4 (et un quatre a cote) 0
exemple2 un full de huit par les valets donne : 6 (full) 8 (de huit) 11 (par les valets) 0 0 0
les as sont affichés 14 (plus fort que les rois)
*/
void decode (int a)
{
    int b,c,d,e,f,g;
    b=a/759375;
    a-=b*759375;
    c=a/50625;
    a-=c*50625;
    d=a/3375;
    a-=d*3375;
    e=a/225;
    a-=e*225;
    f=a/15;
    a-=f*15;
    g=a;
    cout << b << " " << c << " " << d << " " << e << " " << f << " " << g << endl;
}


int main()
{
    srand(time(NULL));

    //CREATION DES BOTS

    Partie laPartie = Partie();

    Joueur joueur1("Alphonse", 100,&laPartie);
    Joueur joueur2("Bebert", 100,&laPartie);
    Joueur joueur3("Charles", 100,&laPartie);
    Joueur joueur4("Dede", 100,&laPartie);

    Joueur lesJoueurs[4] = {joueur1, joueur2, joueur3, joueur4};



    for(unsigned int k=0;k<4;k++)
    {
       laPartie.ajouterJoueur(lesJoueurs[k]);
    }
    //FIN CREATION BOTS

    //CREATION HUMAIN
    string nomPlayer;
    cout<<"Entrez votre nom : ";
    cin>>nomPlayer;

    Joueur player(nomPlayer, 100,&laPartie);
    player.setStrategie(new Humain(&player));

    laPartie.ajouterJoueur(player);
    //FIN CREATION HUMAIN

    laPartie.commencer();


	return 0;
}
