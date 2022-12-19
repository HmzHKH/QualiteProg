#include "joueur.h"
#include "AireDeJeu.h"


joueur::joueur(const Point& pos) : d_pos{pos}, d_alive{True}, d_lifetime{0} {}

int joueur::lifetime() const
{
    return d_lifetime;
}


void joueur::setDeath()
{
    d_alive = False;
}


bool joueur::estVivant() const
{
    return d_alive;
}


Point joueur::position() const
{
    return d_pos;
}




void joueurNormal::deplacement(const AireDeJeu& AdJ,int valeur)
{
    Point d_temp = d_pos;
    switch(valeur)
    {
        case 1:
            d_temp += {-1,1};
            if(AdJ.estDansTableau(d_temp) && !AdJ.estOccupe())
            {
                d_pos = d_temp;
                break;
            }

        case 2:
            d_temp += {0,1};
            if(AdJ.estDansTableau(d_temp) && !AdJ.estOccupe())
            {
                d_pos += d_temp;
                break;
            }
        case 3:
            d_temp += {1,1};
            if(AdJ.estDansTableau(d_temp) && !AdJ.estOccupe())
            {
                d_pos += d_temp;
                break;
            }
        case 4:
            d_temp += {-1,0};
            if(AdJ.estDansTableau(d_temp) && !AdJ.estOccupe())
            {
                d_pos += d_temp;
                break;
            }
        case 6:
            d_temp += {1,0};
            if(AdJ.estDansTableau(d_temp) && !AdJ.estOccupe())
            {
                d_pos += d_temp;
                break;
            }
        case 7:
            d_temp += {-1,-1};
            if(AdJ.estDansTableau(d_temp) && !AdJ.estOccupe())
            {
                d_pos += d_temp;
                break;
            }
        case 8:
            d_temp += {0,-1};
            if(AdJ.estDansTableau(d_temp) && !AdJ.estOccupe())
            {
                d_pos += d_temp;
                break;
            }
        case 9:
            d_temp += {1,-1};
            if(AdJ.estDansTableau(d_temp) && !AdJ.estOccupe())
            {
                d_pos += d_temp;
                break;
            }
    }
    d_lifetime += 1;
}

void joueurExpert::deplacement(const AireDeJeu& AdJ,int valeur)
{
    Point d_temp = d_pos;
    switch(valeur)
    {
        case 2:
            d_temp += {0,1};
            if(AdJ.estDansTableau(d_temp) && !AdJ.estOccupe())
            {
                d_pos += d_temp;
                break;
            }
        case 4:
            d_temp += {-1,0};
            if(AdJ.estDansTableau(d_temp) && !AdJ.estOccupe())
            {
                d_pos += d_temp;
                break;
            }
        case 6:
            d_temp += {1,0};
            if(AdJ.estDansTableau(d_temp) && !AdJ.estOccupe())
            {
                d_pos += d_temp;
                break;
            }
        case 8:
            d_temp += {0,-1};
            if(AdJ.estDansTableau(d_temp) && !AdJ.estOccupe())
            {
                d_pos += d_temp;
                break;
            }
    }
    d_lifetime += 2;
}
