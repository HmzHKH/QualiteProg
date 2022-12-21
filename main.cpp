
#include "fauve.h"
#include "joueur.h"
#include "piege.h"
#include "AireDeJeu.h"
#include <iostream>
#include <vector>

bool gameOver = true; // Mettre false pour que ca fonctionne
bool menu = true;


int SaisieDeplacement()
{
    int valeur = 0;
    while(valeur<1 || valeur>9)
    {
        std::cout<<"envoyez la valeur de deplacement: ";
        std::cin>>valeur;
    }
    return valeur;
}


//il faut initialiser les differents tableaux de pointeurs fauve, piege et joueur?

void jouer()
{
    int val;
    std::vector<std::vector<int>> x;
    x.resize(10);
    for(int i=0;i<x.size();i++)
    {
        x[i].resize(10);
        for(int j =0; j<x[i].size();j++)
        {
            x[i][j]=0;
        }
    }
    point pn {8,5};

    AireDeJeu e{x};
    joueurNormal j{pn};


    int k=0;

    std::vector<std::unique_ptr<fauve>> fauves;
    fauves.push_back(std::make_unique<lion>(pn));
    fauves.push_back(std::make_unique<tigre>(pn));
    std::vector<std::unique_ptr<piegeAPic>> pieges;
    point pi {5,5};
    pieges.push_back(std::make_unique<piegeAPic>(pi,4));
    //initAireDeJeu(AdJ);
    while (!gameOver && fauves[k]!=nullptr)
    {
        val=SaisieDeplacement();
        j.deplacement(e,val);
        for(const auto& d :fauves)
        {
            d->deplacement(e,j,fauves,pieges);// on deplace les fauves
        }
        k++;
    }

}




void afficheAiredj(const std::vector<std::vector<int>>& ADJ)//affichage du tableau et conversion en symboles
{
    for(int i=0; i<ADJ.size();i++)
    {
        for(int j=0;j<ADJ[0].size();j++)
        {
            if(ADJ[i][j]==0)
                std::cout<<'|'<<" "<<'|';
            else if(ADJ[i][j]==1)
                std::cout<<'|'<<'J'<<'|';
            else if(ADJ[i][j]==2)
                std::cout<<'|'<<'L'<<'|';
            else if(ADJ[i][j]==3)
                std::cout<<'|'<<'T'<<'|';
            else if(ADJ[i][j]==4)
                std::cout<<'|'<<'P'<<'|';
        }
        std::cout<<std::endl;
    }
}




int main(){
while (menu)
{
    int valeur;
    std::cout<<"Saisissez ce que vous voulez faire: ";
    std::cin>>valeur;
    switch(valeur)
    {
        case 1 : jouer(); break;
    }
}
}
