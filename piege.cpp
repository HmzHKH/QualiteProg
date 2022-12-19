#include "piege.h"
#include "AireDeJeu.h"

piegeAPic::piegeAPic(const Point& pos, int taille) : d_pos{pos}, d_actif{true}, d_empile{taille} {}

Point piegeAPic::position() const
{
    return d_pos;
}

bool piegeAPic::estActif() const
{
    return d_actif;
}

void piegeAPic::increaseEmpile()
{
    if(d_empile != 0)
    {
        d_empile--;   //reduit la taille du piege si un fauve tombe dedans

        if(d_empile == 0)
        {
            d_actif = false;    //desactive le piege s'il est plein
        }
    }
}
