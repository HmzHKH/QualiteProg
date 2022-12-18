#include "fauve.h"
#include "AireDeJeu.h"

Point fauve::position() const
{
    return d_pos;
}

bool fauve::estVivant() const
{
    return d_alive;
}


lion::lion() : {}

void lion::deplacement(const AireDeJeu& AdJ)
{

}

tigre::tigre() : {}

void tigre::deplacement(const AireDeJeu& AdJ)
{

}
