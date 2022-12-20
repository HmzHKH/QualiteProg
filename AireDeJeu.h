#include <vector>

// 0 dans le tableau = case vide
// 1 dans le tableau = Joueur
// 2 dans le tableau = Fauve
// 3 dans le tableau = StaticEntity

class AireDeJeu{
public:
    AireDeJeu(std::vector<std::vector<int>> tab2D);
    bool estDansTableau(const Point& p) const; //Renvoi si un point est dans le tableau
    bool estOccupe(const Point& p) const; //Renvoi si une case est occupée (case pas égale à 0)
    bool import(const std::string& fichier);
    bool export(const std::string& fichier);
private:
    std::vector<std::vector<int>> d_Tab; 
};
