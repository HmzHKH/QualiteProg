#ifndef AIREDEJEU_H
#define AIREDEJEU_H

#include <vector>
#include <string>

class joueur;
class point;

// 0 dans le tableau = case vide
// 1 dans le tableau = Joueur
// 2 dans le tableau = Lion
// 3 dans le tableau = Tigre
// 4 dans le tableau = StaticEntity

class AireDeJeu{
public:
    AireDeJeu(const std::vector<std::vector<int>> &tab2D);
    bool estDansTableau(const point& p) const; //Renvoi si un point est dans le tableau
    bool estLibre(const point& p) const; //Renvoi si une case est libre (égale à 0)
    point posJoueur(const joueur& j) const;// renvoie la position du joueur au moment donnée
    bool estOccupeType(int e, const point& p) const; //renvoie si un type  d'entite occupe la position p du  tableau

    bool import(const std::string &fichier);
    bool export(const std::string &fichier);
private:
    std::vector<std::vector<int>> d_Tab; 
};

#endif // AIREDEJEU_H


