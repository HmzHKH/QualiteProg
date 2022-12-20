#include "piege.h"
#include "AireDeJeu.h"

piegeAPic::piegeAPic(const Point& pos, int taille) : d_pos{pos}, d_actif{true}, d_taille{taille} {}

Point piegeAPic::position() const
{
    return d_pos;
}

bool piegeAPic::estActif() const
{
    return d_actif;
}

int piegeAPic::taille() const
{
    return d_taille;
}

void piegeAPic::increaseTaille()
{
    if(d_taille != 0)
    {
        d_taille--;   //reduit la taille du piege si un fauve tombe dedans

        if(d_taille == 0)
        {
            d_actif = false;    //desactive le piege s'il est plein
        }
    }
}
