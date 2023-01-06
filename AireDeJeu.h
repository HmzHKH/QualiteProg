#ifndef AIREDEJEU_H
#define AIREDEJEU_H

#include <vector>
#include <string>
#include "joueur.h"
#include "point.h"
#include "fauve.h"
// 0 dans le tableau = case vide
// 1 dans le tableau = Joueur
// 2 dans le tableau = Lion
// 3 dans le tableau = Tigre
// 4 dans le tableau = PiegeAPic

class AireDeJeu{
public:
    AireDeJeu(const std::vector<std::vector<int>> &tab2D);
    AireDeJeu(int largeur, int hauteur); // Initialise un tab avec des 0

    bool estDansTableau(const point& p) const; //Renvoie si un point p est dans le tableau
    bool estOccupeType(int e, const point& p) const; //renvoie si un type  d'entite e occupe la position p du  tableau
    point posJoueur() const;    // renvoie la position du joueur au moment donnée
    void setValue(const point& p, int value); //affecte la case p avec la valeur value
    bool import(const std::string &fichier);  //importel'aire de jeu depuis un fichier passe en parametre
    void applyImport(std::vector<std::unique_ptr<joueur>> &joueurs,std::vector<std::unique_ptr<fauve>> &fauves, std::vector<std::unique_ptr<piegeAPic>> &pieges); // mise a jour des tableaux de pointeurs a partir de l'aire de jeu
    bool exporter(const std::string &fichier); // exportation de l'aire de jeu  vers le fichier passe en parametre
    int tailleL() const; //taille des lignes
    int tailleC() const; //taille des colonnes
private:
    std::vector<std::vector<int>> d_Tab;
};

#endif // AIREDEJEU_H



