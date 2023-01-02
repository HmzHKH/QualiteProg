#include "Afficheur.h"
#include "point.h"

#include "iomanip"
#include "iostream"


void afficheConsole::afficheAdj(const AireDeJeu &Adj) const
{



    for(int i=0; i<Adj.tailleL();i++)
    {


        for(int k=0; k<Adj.tailleL()*6;k++)
            std::cout<<std::left<<std::setw(1)<<'-';

        std::cout<<std::endl;




        for(int j=0;j<Adj.tailleC();j++)
        {
            point p{i,j};
            std::cout<<std::left<<std::setw(3)<<'|'<<std::left<<std::setw(3);
            if(Adj.estOccupeType(0,p))
                {
                if(Adj.tailleL()==j+1)
                    std::cout<<' '<<'|';
                else
                    std::cout<<' ';
                }

            else if(Adj.estOccupeType(1,p))
                {
                if(Adj.tailleL()==j+1)
                    std::cout<<'J'<<'|';
                else
                    std::cout<<'J';
                }
            else if(Adj.estOccupeType(2,p))
                {
                if(Adj.tailleL()==j+1)
                    std::cout<<'L'<<'|';
                else
                    std::cout<<'L';
                }

            else if(Adj.estOccupeType(3,p))
                {
                if(Adj.tailleL()==j+1)
                    std::cout<<'T'<<'|';
                else
                    std::cout<<'T';
                }
            else if(Adj.estOccupeType(4,p))
                {
                if(Adj.tailleL()==j+1)
                    std::cout<<'P'<<'|';
                else
                    std::cout<<'P';
                }



        }
        std::cout<<std::endl;
    }
    for(int k=0; k<Adj.tailleL()*6;k++)
            std::cout<<std::left<<std::setw(1)<<'-';

        std::cout<<std::endl;
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
