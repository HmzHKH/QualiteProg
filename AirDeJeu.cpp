#include"AireDeJeu.h"

AireDeJeu::AireDeJeu(std::vector<std::vector<int>> tab2D):
    d_Tab{tab2D}
{}

bool AireDeJeu::estDansTableau(const Point& p) const
{
    for(int i = 0; i < d_Tab.size(); i++)
    {
        for(int j = 0; j < d_Tab[j].size(); j++)
            return p.x = i && p.y = j;
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
