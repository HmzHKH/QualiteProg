#ifndef AIREDEJEU_H
#define AIREDEJEU_H



#include <vector>
#include "joueur.h"

// 0 dans le tableau = case vide
// 1 dans le tableau = Joueur
// 2 dans le tableau = Lion
// 3 dans le tableau = Tigre
// 4 dans le tableau = StaticEntity

class AireDeJeu{
public:
    AireDeJeu(const std::vector<std::vector<int>> &tab2D);
    bool estDansTableau(const Point& p) const; //Renvoi si un point est dans le tableau
    bool estOccupe(const Point& p) const; //Renvoi si une case est occupée (case pas égale à 0)
    Point posJoueur(const joueur& j) const;// renvoie la position du joueur au moment donnée
    bool estOccupeType(int e, const Point& p) const; //renvoie si un type  d'entite occupe la position p du  tableau



private:
    std::vector<std::vector<int>> d_Tab;
};








#endif // AIREDEJEU_H



