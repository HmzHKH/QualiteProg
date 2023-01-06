#include "fauve.h"
#include "joueur.h"
#include "piege.h"
#include "AireDeJeu.h"
#include "Afficheur.h"
#include <iostream>
#include <vector>

bool gameOver; //variable qui sert à stopper la boucle principale
bool menu = true;

void ajoutEdit(AireDeJeu& e, afficheConsole& a) //methode qui permet l'edition d'une aire de jeu
{
    bool ajouter=true;
    while(ajouter)
    {
        std::string nom;
        std::cout<<"Ecrire ce que vous voulez ajouter: joueur,lion,tigre,piege a pic\n";
        std::cin>>nom;
        if(nom == "joueur")
        {
            int x,y;
            std::cout<<"Donnez sa position: y x\n";
            std::cin>>y>>x;
            e.setValue(point{x,y},1);
        }
        else if(nom == "lion")
        {
            int x,y;
            std::cout<<"Donnez sa position: y puis x\n";
            std::cin>>y>>x;
            e.setValue(point{x,y},2);
        }
        else if(nom == "tigre")
        {
            int x,y;
            std::cout<<"Donnez sa position: y puis x\n";
            std::cin>>y>>x;
            e.setValue(point{x,y},3);
        }
        else if(nom == "piege")
        {
            int x,y;
            std::cout<<"Donnez sa position: y puis x\n";
            std::cin>>y>>x;
            e.setValue(point{x,y},4);
        }
        else std::cout<<"error";
        a.afficheAdj(e);
        std::cout<<"Voulez vous continuer d'ajouter des entites? 0.Non 1.Oui\n";
        std::cin>>ajouter;
    }
}

void creeAdJ() // methode qui permet la creation d'une aire de jeu a partir de la console
{
    afficheConsole a;
    int longueur,largeur;
    std::cout<<"Donnez la taille de l'aire de jeu: Longueur Largeur\n";
    std::cin>>longueur>>largeur;
    AireDeJeu adj(longueur,largeur);
    std::cout<<"0 dans le tableau = case vide\n1 dans le tableau = Joueur\n2 dans le tableau = Lion\n3 dans le tableau = Tigre\n4 dans le tableau = PiegeAPic\n";
    a.afficheAdj(adj);
    ajoutEdit(adj,a);
    adj.exporter("export.txt");
    std::cout<<"Fichier exporte avec succes dans export.txt\n";
}

void editImport() //methode permettant de modifier le fichier importé
{
    afficheConsole a;
    AireDeJeu adj{10,10};
    adj.import("import.txt"); //fichier importe
    a.afficheAdj(adj);
    ajoutEdit(adj,a);
    adj.exporter("export.txt");
    std::cout<<"Fichier exporte avec succes dans export.txt\n";

}

void exporte() //methode qui permet d exporter l'aire de jeu sur le fichier export.Txt
{
    int choix =0;
    while(choix<1 || choix>3)
    {
        std::cout<<"Saisissez ce que vous voulez faire:\n1. Creer une aire de jeu vierge\n2. Modifier l'aire de jeu importee \n3. Revenir au menu\n";
        std::cin>>choix;
    }
    switch(choix)
    {
        case 1: creeAdJ();break;
        case 2: editImport();break;
        case 3: break;
    }
}
void jeu(AireDeJeu& adj, afficheConsole& a) //boucle principale du jeu
{
    //Init tab joueurs
    std::vector<std::unique_ptr<joueur>> joueurs;
    //Init tab fauves
    std::vector<std::unique_ptr<fauve>> fauves;
    //Init tab pieges
    std::vector<std::unique_ptr<piegeAPic>> pieges;
    adj.applyImport(joueurs,fauves,pieges); //importation depuis l aire de jeu des fauves pieges et du joueur dans les tableaux respectif

    //boucle de jeu tour par tour
    while (gameOver==false && fauves.empty()==false)
    {
        a.afficheAdj(adj);
        int valeur;
        std::cout<<"envoyez la valeur de deplacement: ";
        std::cin>>valeur;
        for(int i=0;i<joueurs.size();++i)
        {
            joueurs[i]->deplacement(adj,valeur);
        }
        for(int i=0;i<fauves.size();++i)
        {
            if(fauves[i]->estVivant())
            {
                fauves[i]->deplacement(adj,joueurs,fauves,pieges);// on deplace chaque  fauve du tableau
                if(joueurs[0]->estVivant()==false)
                {
                    gameOver=true;
                    i=fauves.size();
                }
            }
        }
        for(int i=0;i<pieges.size();++i) //Supprime les pieges inactifs
        {
            if(!pieges[i]->estActif())
            {
                std::swap(pieges[i],pieges[pieges.size()-1]);
                pieges.pop_back();
            }
        }
        for(int i=0;i<joueurs.size();++i)
        {
            std::cout<<"Score du joueur: "<<joueurs[i]->lifetime()<<'\n';
        }

    }

    a.afficheGameOver();
    std::cout<<"GameOver\nRetour au menu...\n";
}
void jouer() //initialisation de l'aire de jeu et lance la boucle principale
{
    gameOver=false;
    //Init afficheur
    afficheConsole a;
    //Init Aire de jeu
    AireDeJeu adj{10,10};
    int typeAdJ =0;
    while(typeAdJ<1 || typeAdJ>3)
    {
        std::cout<<"Saisissez ce que vous voulez faire:\n1. Aire de jeu aleatoire(not working)\n2. Aire de jeu importee\n3. Revenir au menu\n";
        std::cin>>typeAdJ;
    }
    switch(typeAdJ)
    {
        case 1: std::cout<<"N'existe pas, uniquement une idee pour etoffer le menu\n";break;  //aleatoireAdJ(e); Idee de type d'aire de jeu
        case 2: adj.import("import.txt");jeu(adj,a); break;
        case 3: break;
    }
}

void Tutoriel()
{
    std::cout<<R"( Voici les commandes de jeu, RAPPEL un joueur expert se deplace qu en diagonales:


                            7     8      9
                            ^     ^     ^
                             \    |    /
                              \   |   /
                               \  |  /
                                \ | /
                        4<--------O-------->6
                                 /|\
                                / | \
                               /  |  \
                              /   |   \
                             v    v    v

                             1    2     3



)" << '\n';
}

void mainMenu()
{
    while (menu)
    {
        int valeur;
        std::cout<<"Saisissez ce que vous voulez faire:\n1. Jouer\n2. Exporter une Aire de Jeu\n3. Tutoriel \n9. Quitter\n";
        std::cin>>valeur;
        switch(valeur)
        {
            case 1 : jouer(); break;
            case 2 : exporte(); break;
            case 3 : Tutoriel(); break;
            case 9 : exit(0); break;
        }
    }
}

int main()
{
    mainMenu();
}
