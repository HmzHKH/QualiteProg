#include "joueur.h"




joueur::joueur(const point& pos) : d_pos{pos}, d_alive{true}, d_lifetime{0}
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


point joueur::position() const
{
    return d_pos;
}

void joueur::deplacementJoueur(AireDeJeu& AdJ, const point & d_temp) //fonction qui effectue le deplacement si la position en parametre respecte les limites et si elle est vide
{
    if(AdJ.estDansTableau(d_temp) && AdJ.estOccupeType(0,d_temp))
            {
                AdJ.setValue(d_pos,0);
                d_pos=d_temp;
                AdJ.setValue(d_pos,1);
            }
}



joueurNormal::joueurNormal(const point& pos) : joueur{pos}
{}


void joueurNormal::deplacement( AireDeJeu& AdJ,int valeur)
{
    point d_temp = d_pos;
    switch(valeur) //un switch qui suite aux valeur numeriques reçue il va executer un deplacement
    {
        case 1: // le joueur se deplace vers la diagonales bas gauche
            d_temp.sety(d_temp.y()-1);
            d_temp.setx(d_temp.x()+1);
            deplacementJoueur(AdJ,d_temp);
            break;

        case 2: //deplacement vers le bas
            d_temp.setx(d_temp.x()+1);
            deplacementJoueur(AdJ,d_temp);
            break;
        case 3: //deplacement vers la diagonale bas droite
            d_temp.sety(d_temp.y()+1);
            d_temp.setx(d_temp.x()+1);
            deplacementJoueur(AdJ,d_temp);
            break;
        case 4: //deplacement vers la gauche
            d_temp.sety(d_temp.y()-1);
            deplacementJoueur(AdJ,d_temp);
            break;
        case 6://deplacement vers la droite
            d_temp.sety(d_temp.y()+1);
            deplacementJoueur(AdJ,d_temp);
            break;
        case 7://deplacement vers la diagonale haut gauche
            d_temp.sety(d_temp.y()-1);
            d_temp.setx(d_temp.x()-1);
            deplacementJoueur(AdJ,d_temp);
            break;
        case 8: //deplacement vers le haut
            d_temp.setx(d_temp.x()-1);
            deplacementJoueur(AdJ,d_temp);
            break;
        case 9: ////deplacement vers la diagonale haut droite
            d_temp.sety(d_temp.y()+1);
            d_temp.setx(d_temp.x()-1);
            deplacementJoueur(AdJ,d_temp);
            break;
    }
    d_lifetime += 1; //augmentation du score à la fin d'un mouvement executé
}

joueurExpert::joueurExpert(const point& pos) : joueur{pos}
{}

void joueurExpert::deplacement( AireDeJeu& AdJ,int valeur) //meme chose que pour le joueurNormal mais sans mouvement h et v
{
    point d_temp = d_pos;
    switch(valeur)
    {
        case 2:
            d_temp.setx(d_temp.x()+1);
            deplacementJoueur(AdJ,d_temp);
            break;
        case 4:
            d_temp.sety(d_temp.y()-1);
            deplacementJoueur(AdJ,d_temp);
            break;
        case 6:
            d_temp.sety(d_temp.y()+1);
            deplacementJoueur(AdJ,d_temp);
            break;
        case 8:
            d_temp.setx(d_temp.x()-1);
            deplacementJoueur(AdJ,d_temp);
            break;
    }
    d_lifetime += 2;
}
