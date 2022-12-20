#include "joueur.h"
#include "AireDeJeu.h"



joueur::joueur(const Point& pos) : d_pos{pos}, d_alive{true}, d_lifetime{0}
{}

int joueur::lifetime() const
{
    return d_lifetime;
}


void joueur::setDeath()
{
    d_alive = false;
}


bool joueur::estVivant() const
{
    return d_alive;
}


Point joueur::position() const
{
    return d_pos;
}



joueurNormal::joueurNormal(const Point& pos) : joueur{pos}
{}


void joueurNormal::deplacement( AireDeJeu& AdJ,int valeur)
{
    Point d_temp = d_pos;
    switch(valeur)
    {
        case 1:
            d_temp.x--;
            d_temp.y++;
            if(AdJ.estDansTableau(d_temp) && !AdJ.estOccupe(d_temp))
            {
                d_pos = d_temp;
                break;
            }

        case 2:
            d_temp.y++;
            if(AdJ.estDansTableau(d_temp) && !AdJ.estOccupe(d_temp))
            {
                d_pos = d_temp;
                break;
            }
        case 3:
            d_temp.x++;
            d_temp.y++;
            if(AdJ.estDansTableau(d_temp) && !AdJ.estOccupe(d_temp))
            {
                d_pos = d_temp;
                break;
            }
        case 4:
            d_temp.x--;
            if(AdJ.estDansTableau(d_temp) && !AdJ.estOccupe(d_temp))
            {
                d_pos = d_temp;
                break;
            }
        case 6:
            d_temp.x++;
            if(AdJ.estDansTableau(d_temp) && !AdJ.estOccupe(d_temp))
            {
                d_pos = d_temp;
                break;
            }
        case 7:
            d_temp.x--;
            d_temp.y--;
            if(AdJ.estDansTableau(d_temp) && !AdJ.estOccupe(d_temp))
            {
                d_pos = d_temp;
                break;
            }
        case 8:
            d_temp.y--;
            if(AdJ.estDansTableau(d_temp) && !AdJ.estOccupe(d_temp))
            {
                d_pos = d_temp;
                break;
            }
        case 9:
            d_temp.x++;
            d_temp.y--;
            if(AdJ.estDansTableau(d_temp) && !AdJ.estOccupe(d_temp))
            {
                d_pos = d_temp;
                break;
            }
    }
    d_lifetime += 1;
}

joueurExpert::joueurExpert(const Point& pos) : joueur{pos}
{}

void joueurExpert::deplacement( AireDeJeu& AdJ,int valeur)
{
    Point d_temp = d_pos;
    switch(valeur)
    {
        case 2:
            d_temp.y++;
            if(AdJ.estDansTableau(d_temp) && !AdJ.estOccupe(d_temp))
            {
                d_pos = d_temp;
                break;
            }
        case 4:
            d_temp.x--;
            if(AdJ.estDansTableau(d_temp) && !AdJ.estOccupe(d_temp))
            {
                d_pos = d_temp;
                break;
            }
        case 6:
            d_temp.x++;
            if(AdJ.estDansTableau(d_temp) && !AdJ.estOccupe(d_temp))
            {
                d_pos = d_temp;
                break;
            }
        case 8:
            d_temp.y--;
            if(AdJ.estDansTableau(d_temp) && !AdJ.estOccupe(d_temp))
            {
                d_pos = d_temp;
                break;
            }
    }
    d_lifetime += 2;
}
