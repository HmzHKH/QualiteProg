
#include "fauve.h"
#include "joueur.h"
#include "piege.h"
#include "AireDeJeu.h"
#include "Afficheur.h"
#include <iostream>
#include <vector>
/*
bool gameOver = true; // Mettre false pour que ca fonctionne
bool menu = true;


int SaisieDeplacement()
{
    int valeur = 0;
    while(valeur<1 || valeur>9)
    {
        std::cout<<"envoyez la valeur de deplacement: ";
        std::cin>>valeur;
    }
    return valeur;
}


void mainMenu()
{
    while (menu)
    {
        int valeur;
        std::cout<<"Saisissez ce que vous voulez faire:\n1. Jouer\n9. Quitter\n";
        std::cin>>valeur;
        switch(valeur)
        {
            case 1 : jouer(); break;
            case 9 : break;
        }
    }
}


//il faut initialiser les differents tableaux de pointeurs fauve, piege et joueur?

void jouer()
{

    //Init Aire de jeu
    AireDeJeu e{10,10};
    int valeurAdJ=0;
    while(valeurAdJ<1 || valeurAdJ>3)
    {
        std::cout<<"Saisissez ce que vous voulez faire:\n1. Aire de jeu aléatoire\n2. Aire de jeu importée\n3. Revenir au menu\n";
        std::cin>>valeurAdJ;
    }
    switch(valeurAdJ)
    {
        case 1:  break;  //aleatoireAdJ(e); On mettra le nombre de fauves, de pieges etc en parametres
        case 2: e.import("import.txt"); break;
        case 3: mainMenu();
    }

    //Init joueur
    bool estExpert=false;
    std::cout<<"Joueur Expert ? True/False\n";
    std::cin>>estExpert;
    if(estExpert)
        joueurExpert j{e.posJoueur()};
    else
        joueurNormal j{e.posJoueur()};

    //Init tab fauves
    std::vector<std::unique_ptr<fauve>> fauves;
    for(int i = 0; i < 10; i++)
    {
        for(int k = 0; k < 10; k++)
        {
            if(e.estOccupeType(2, point{i,k}))
                fauves.push_back(std::make_unique<lion>(point{i,k}));

            else if(e.estOccupeType(3, point{i,k}))
                fauves.push_back(std::make_unique<tigre>(point{i,k}));
        }
    }

    //Init tab pieges
    std::vector<std::unique_ptr<piegeAPic>> pieges;
    for(int i = 0; i < 10; i++)
    {
        for(int k = 0; k < 10; k++)
        {
            if(e.estOccupeType(4, point{i,k}))
                pieges.push_back(std::make_unique<piegeAPic>(point{i,k},4));
        }
    }

    //boucle de jeu tour par tour
    while (!gameOver || !fauves.empty())
    {
        e.affiche();
        int val = SaisieDeplacement();
        j.deplacement(e,val);
        for(const auto& d :fauves)
        {
            d->deplacement(e,j,fauves,pieges);// on deplace les fauves
        }

        for(int i=0;i<pieges.size();++i) //Supprime les pieges inactifs
        {
            if(!pieges[i]->estActif())
            {
                std::swap(pieges[i],pieges[pieges.size()-1]);
                pieges.pop_back();
            }
        }
    }

}
*/

int main()
{
    //mainMenu();
    afficheConsole a;
    AireDeJeu Adj{5,5};
    a.afficheAdj(Adj);
    std::cout<<std::endl;

    point p(4,4);
    point p1(2,2);
    Adj.setValue(p,1);
    Adj.setValue(p1,1);
    a.afficheAdj(Adj);

    std::cout<<std::endl;
    //Adj.import("test.txt");
    //a.afficheAdj(Adj);
    //a.afficheJ(Adj);

}
