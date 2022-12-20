#ifndef JOUEUR_H
#define JOUEUR_H



#include "entity.h"


class joueur : public DynamicEntity{
public:
    joueur(const Point& pos);

    int lifetime() const;
    void setDeath();
    bool estVivant() const override;
    Point position() const override;
    virtual void deplacement( AireDeJeu& AdJ, int valeur) = 0;
protected:
    Point d_pos;
    bool d_alive;
    int d_lifetime;
};

// Avance avec diagonales
class joueurNormal : public joueur{
public:
    joueurNormal(const Point& pos);
    void deplacement( AireDeJeu& AdJ, int valeur) override;
};

// Avance sans diagonales
class joueurExpert : public joueur{
public:
    joueurExpert(const Point& pos);
    void deplacement( AireDeJeu& AdJ, int valeur) override;
};



#endif // JOUEUR_H



