#include "fauve.h"
#include "AireDeJeu.h"
#include "joueur.h"
#include <utility>



fauve::fauve(const point& pos) : d_pos{pos}, d_alive{true}
{}

point fauve::position() const
{
    return d_pos;
}

bool fauve::estVivant() const
{
    return d_alive;
}

void killFauve(const point& p,std::vector<std::unique_ptr<fauve>> &fauves)
{
    for(int i=0; i<fauves.size();i++)
    {
        if(fauves[i]->position()==p)
        {
            std::swap(fauves[i],fauves[fauves.size()-1]);
            fauves.pop_back();
        }
    }
}


void killPiegeAPic(const point& p, std::vector<std::unique_ptr<piegeAPic>> &pieges, std::vector<std::unique_ptr<fauve>> &fauves)  // fonction qui s'occupe de verifier si dans la position p il y a un piege et si oui on tue le fauve dans cette pos et empile le piege
{
    for(int i=0; i<pieges.size();i++)
    {
        if(pieges[i]->position()==p)
        {
            if(pieges[i]->estActif())
            {
                killFauve(p,fauves);
                pieges[i]->increaseTaille();
            }
        }
    }
}


lion::lion(const point& pos) : fauve{pos}
{}
//fauve se deplacant en h et v
void lion::deplacement( AireDeJeu& AdJ, joueur &j,std::vector<std::unique_ptr<fauve>> &fauves, std::vector<std::unique_ptr<piegeAPic>> &pieges)
{
    int lx=unsigned(d_pos.x()-j.position().x());
    int ly=unsigned(d_pos.y()-j.position().y());
    point temp=d_pos;

    if(lx>ly) //on choisit la meilleure voie par la quelle avancer ou reculer
    {
        if(d_pos.x()<j.position().x()) //si le lion est � gauche du joueur il avancera vers la droite
            temp.setx(temp.x()+1);
        else
            temp.setx(temp.x()-1);         //si le lion est � droite du joueur il avancera vers la gauche
    }

    else
    {
        if(d_pos.y()<j.position().y())//si le lion est en haut du joueur il avancera vers le haut
            temp.sety(temp.y()+1); 
        else
            temp.sety(temp.y()-1);    //si le lion est en bas du joueur il avancera vers le haut
    }

    if(AdJ.estOccupeType(3,temp)) //si le lion avance sur un tigre il le tue et prend sa place
    {
        killFauve(temp,fauves);
        d_pos=temp;
    }

    else if(AdJ.estOccupeType(0,temp)) // si le lion avance sur une position vide il prend cette place
        d_pos=temp;

    else if(AdJ.estOccupeType(4,temp)) // si le lion  avance vers un piege il se deplace et meurt si le piege n'est pas vide(pour le moment il y a pas d'arbres)
    {
        d_pos=temp;
        killPiegeAPic(d_pos,pieges,fauves);//on empile et on tue le tigre s'il est sur un piege actif
    }

    else if(AdJ.estOccupeType(1,temp))
    {
        d_pos=temp;
        j.setDeath();
    }
}


tigre::tigre(const point& pos) : fauve{pos}
{}


//diagonales
void tigre::deplacement( AireDeJeu& AdJ, joueur &j,std::vector<std::unique_ptr<fauve>> &fauves, std::vector<std::unique_ptr<piegeAPic>> &pieges)
{
    int lx=unsigned(d_pos.x()-j.position().x());
    int ly=unsigned(d_pos.y()-j.position().y());
    point temp=d_pos;

    if(lx>ly)//on choisit la meilleure voie par la quelle avancer ou reculer
    {
        if(d_pos.x()<j.position().x())
            temp.setx(temp.x()+1);//si le tigre est � gauche du joueur il avancera vers la droite
        else
            temp.setx(temp.x()-1);//si le tigre est � droite du joueur il avancera vers la gauche


    }

    else if(lx<ly)
    {
        if(d_pos.y()<j.position().y())
            temp.sety(temp.y()+1); //si le tigre est en bas du joueur il avancera vers le haut
        else
            temp.sety(temp.y()-1); //si le tigre est en haut du joueur il avancera vers le bas
    }

    else//deplace le tigre en diagonale
    {
        if(d_pos.y()<j.position().y())
            temp.sety(temp.y()+1);
        else
            temp.sety(temp.y()-1);

        if(d_pos.x()<j.position().x())
            temp.setx(temp.x()+1);
        else
            temp.setx(temp.x()-1);

    }

    if(AdJ.estOccupeType(2,temp)) //s il avance vers un lion il le tue
    {
        killFauve(temp,fauves);
        d_pos=temp;
    }

    else if(AdJ.estOccupeType(0,temp))//si cest vide il avance
        d_pos=temp;

    else if(AdJ.estOccupeType(4,temp))// si le tigre avance vers un piege il se deplace et meurt si le piege n'est pas vide(pour le moment il y a pas d'arbres)
    {
        d_pos=temp;
        killPiegeAPic(d_pos,pieges,fauves);
    }

    else if(AdJ.estOccupeType(1,temp))// si le tigre avance vers le joueur et le tue
    {
        d_pos=temp;
        j.setDeath();
    }
}
