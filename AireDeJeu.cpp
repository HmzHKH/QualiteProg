#include"AireDeJeu.h"
#include"point.h"
#include"joueur.h"
#include <fstream>

AireDeJeu::AireDeJeu(const std::vector<std::vector<int>> &tab2D): d_Tab{tab2D}
{}
AireDeJeu::AireDeJeu(int largeur, int hauteur): d_Tab{}
{
    d_Tab.resize(hauteur);
    for(int i=0;i<d_Tab.size();i++)
    {

        d_Tab[i].resize(largeur);
        for(int j =0; j<d_Tab[i].size();j++)
        {
            d_Tab[i][j]=0;
        }
    }
}

bool AireDeJeu::estDansTableau(const point& p) const
{
    for(int i = 0; i < d_Tab.size(); i++)
    {
        for(int j = 0; j < d_Tab[j].size(); j++)
            return p.x() == i && p.y() == j;
    }
}

bool AireDeJeu::estLibre(const point& p) const
{
    return d_Tab[p.x()][p.y()] == 0;
}

bool AireDeJeu::estOccupeType(int e, const point& p) const
{
    return d_Tab[p.x()][p.y()]==e;
}

point AireDeJeu::posJoueur() const
{
    for(int i = 0; i < d_Tab.size(); i++)
    {
        for(int j = 0; j < d_Tab[j].size(); j++)
            if(d_Tab[i][j] == 1)
            {
                return point{i,j};
            }
    }
}

void AireDeJeu::affiche() const
{
    for(int i=0; i<d_Tab.size();i++)
    {
        for(int j=0;j<d_Tab[0].size();j++)
        {
            if(d_Tab[i][j]==0)
                std::cout<<'|'<<" "<<'|';
            else if(d_Tab[i][j]==1)
                std::cout<<'|'<<'J'<<'|';
            else if(d_Tab[i][j]==2)
                std::cout<<'|'<<'L'<<'|';
            else if(d_Tab[i][j]==3)
                std::cout<<'|'<<'T'<<'|';
            else if(d_Tab[i][j]==4)
                std::cout<<'|'<<'P'<<'|';
        }
        std::cout<<std::endl;
    }
}

// MES AJOUTS:
/* Structure du fichier:
(possible d'ecrire des infos ici avant la structure)
START
TAILLE 4 5
0 0 0 1 0
2 3 0 0 0
4 0 0 3 0
3 0 0 0 2
END
*/

bool AireDeJeu::import(const std::string& fichier)
{
    std::ifstream ist(fichier);
    if(ist)
    {
        int largeur=0;
        int hauteur=0;
        int valeur=0;
        std::string chaine;
        while(chaine != "START")
        {
            ist>>chaine;
        }
        if(ist)
        {
            while(chaine != "TAILLE")
                ist>>chaine;
            if(ist)
            {
                ist>>largeur>>hauteur;
                d_Tab.resize(hauteur);
                for(int i=0;i<d_Tab.size();++i)
                    d_Tab[i].resize(largeur);
                for(int i=0;i<d_Tab.size();++i)
                    for(int j=0;i<d_Tab[i].size();++j)
                    {
                        ist>>valeur;
                        d_Tab[i][j] = valeur;
                    }
                while(chaine != "END")
                    ist>>chaine;
                if(ist)
                    return true;
                else
                {
                    std::cout<<"END not found";
                    return false;
                }
            }
            else
            {
                std::cout<<"Size not found";
                return false;
            }
        }
        else
        {
            std::cout<<"START not found";
            return false;
        }
    }
    else
    {
        std::cout<<"File not found";
        return false;
    }
}

bool AireDeJeu::exporter(const std::string& fichier)
{
    std::ofstream ost(fichier);
    if(ost)
    {
        ost<<"START"<<'\n'<<"TAILLE "<<d_Tab.size()<<" "<<d_Tab[0].size()<<'\n';
        for(int i=0;i<d_Tab.size();++i)
        {
            for(int j=0;j<d_Tab[i].size();++j)
                ost<<d_Tab[i][j]<<" ";
            ost<<'\n';
        }
        ost<<"END";
        return true;
    }
    else
    {
        std::cout<<"File not found";
        return false;
    }
}
