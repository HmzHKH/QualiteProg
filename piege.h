#ifndef PIEGE_H
#define PIEGE_H

#include "entity.h"

class piege : public StaticEntity
{
public:
    virtual ~piege() = default;
};

class piegeAPic : public piege
{
public:
    piegeAPic(const point& pos, int taille);
    point position() const override;
    bool estActif() const override;
    int taille() const;
    void increaseTaille(AireDeJeu& AdJ); //fonction qu empile le piege lorsqu il est traverse par un fauve
private:
    point d_pos;
    bool d_actif;
    int d_taille; //valeur qui indique combien de fauve peut empiler
};

#endif // PIEGE_H
