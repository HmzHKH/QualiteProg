#include"AireDeJeu.h"

AireDeJeu::AireDeJeu(std::vector<std::vector<int>> tab2D):
    d_Tab{tab2D}
{}

bool AireDeJeu::estDansTableau(const Point& p) const
{
    for(int i = 0; i < d_Tab.size(); i++)
    {
        for(int j = 0; j < d_Tab[j].size(); j++)
            return p.x == i && p.y == j;
    }
}

bool AireDeJeu::estOccupe(const Point& p) const
{
    for(int i = 0; i < d_Tab.size(); i++)
    {
        for(int j = 0; j < d_Tab[j].size(); j++)
            return d_Tab[i][j] != 0;
    }
}

Point AireDeJeu::posJoueur(Const joueur& j) const
{
    return j.position();
}


bool AireDeJeu::estOccupeType(int e, const Point& p) const
{
    return d_Tab[p.x][p.y]==e;

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
    ifstream ist(fichier);
    if(ist)
    {
        int largeur=0;
        int hauteur=0;
        int valeur=0;
        std::string chaine;
        while(ist != "START")
        {
            ist>>chaine;
        }
        if(ist)
        {
            while(ist != "TAILLE")
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
                        d_pos[i][j] = valeur;
                    }  
                while(ist != "END")
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

bool AireDeJeu::export(const std::string& fichier)
{
    ostream ost(fichier);
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