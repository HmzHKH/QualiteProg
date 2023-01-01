
#include "fauve.h"
#include "joueur.h"
#include "piege.h"
#include "AireDeJeu.h"
#include <iostream>
#include <vector>

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
        case 1: /*aleatoireAdJ(e); On mettra le nombre de fauves, de pieges etc en parametres*/ break;
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
        for(int j = 0; j < 10; j++)
        {
            if(e.estOccupeType(2, point{i,j}))
                fauves.push_back(std::make_unique<lion>(point{i,j}));

            else if(e.estOccupeType(3, point{i,j}))
                fauves.push_back(std::make_unique<tigre>(point{i,j}));
        }
    }

    //Init tab pieges
    std::vector<std::unique_ptr<piegeAPic>> pieges;
    for(int i = 0; i < 10; i++)
    {
        for(int j = 0; j < 10; j++)
        {
            if(e.estOccupeType(4, point{i,j}))
                pieges.push_back(std::make_unique<piegeAPic>(point{i,j},4));
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
int main()
{
    mainMenu();

}
