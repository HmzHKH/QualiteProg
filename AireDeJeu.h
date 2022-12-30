#ifndef AIREDEJEU_H
#define AIREDEJEU_H

#include <vector>
#include <string>
#include "point.h"
#include "joueur.h"



// 0 dans le tableau = case vide
// 1 dans le tableau = Joueur
// 2 dans le tableau = Lion
// 3 dans le tableau = Tigre
// 4 dans le tableau = PiegeAPic

class AireDeJeu{
public:
    AireDeJeu(const std::vector<std::vector<int>> &tab2D);
    AireDeJeu(int largeur, int hauteur); // Initialise un tab avec des 0
    bool estDansTableau(const point& p) const; //Renvoi si un point est dans le tableau
    bool estLibre(const point& p) const; //Renvoi si une case est libre (égale à 0)
    bool estOccupeType(int e, const point& p) const; //renvoie si un type  d'entite occupe la position p du  tableau

    point posJoueur() const;// renvoie la position du joueur au moment donnée
    void affiche() const;
    bool import(const std::string &fichier);
    bool exporter(const std::string &fichier);
private:
    std::vector<std::vector<int>> d_Tab;
};

#endif // AIREDEJEU_H


