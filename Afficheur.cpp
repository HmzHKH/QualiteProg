#include "Afficheur.h"
#include "point.h"






void afficheConsole::afficheAdj(const AireDeJeu &Adj) const
{

    for(int i=0; i<Adj.tailleL();i++)
    {
        for(int j=0;j<=Adj.tailleC();j++)
        {
            if(j==Adj.tailleC())
                std::cout<<'|'<<std::flush;
            else
                std::cout<<'|'<<'_';
                /*
            if(Adj.estOccupeType(0,p))
                std::cout<<'|'<<" "<<'|';
            else if(Adj.estOccupeType(1,p))
                std::cout<<'|'<<'J'<<'|';
            else if(Adj.estOccupeType(2,p))
                std::cout<<'|'<<'L'<<'|';
            else if(Adj.estOccupeType(3,p))
                std::cout<<'|'<<'T'<<'|';
            else if(Adj.estOccupeType(4,p))
                std::cout<<'|'<<'P'<<'|';
                */
        }
        std::cout<<std::endl;
    }
}

void afficheConsole::afficheJ(const AireDeJeu &Adj) const
{

    for(int i=0; i<Adj.tailleL();i++)
    {
        for(int j=0;j<Adj.tailleC();j++)
        {
            point p{i,j};

            if(Adj.estOccupeType(1,p))
                std::cout<<'|'<<'J'<<'|';

        }

    }
}
