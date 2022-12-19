#include "fauve.h"
#include "joueur.h"
#include "piege.h"
#include <iostream>
#include <vector>

bool gameOver = true;;
bool menu = true;

while (menu)
{
    std::string valeur;
    cout<<"Saisissez ce que vous voulez faire: "
    std::cin>>valeur;
    switch(valeur)
    {
        case "Jouer" : jouer(); break; 
    }
}
    
void jouer()
{
    int val;
    std::vector<std::vector<int>> AireDeJeu;
    joueur j;
    std::vector<fauve> fauves;
    std::vector<piegeAPic> pieges;
    initAireDeJeu(AdJ);
    while (!gameOver && !fauve[i].empty())
    {
        val=SaisieDeplacement();
        j.deplacement(val);
        for(int i=0;i<fauves.size();++i)
        {
            fauves[i].deplacement(AireDeJeu,j,fauves,pieges);// on deplace les fauves
        }
    }

}

int Saisiedeplacement()
{
    int valeur = 0;
    while(valeur<1 || valeur>9)
    {
        cout<<"envoyez la valeur de deplacement: ";
        cin>>valeur;
    }
    return valeur;   
}


void afficheAiredj(const std::vector<std::vector<int>>& ADJ)//affichage du tableau et conversion en symboles
{
    for(int i=0; i<ADJ.size();i++)
    {
        for(int j=0;j<ADJ[0].size();j++)
        {
            if(ADJ[i][j]==0)
                cout<<'|'<<" "<<'|';
            else if(ADJ[i][j]==1)
                cout<<'|'<<'J'<<'|';
            else if(ADJ[i][j]==2)
                cout<<'|'<<'L'<<'|';
            else if(ADJ[i][j]==3)
                cout<<'|'<<'T'<<'|';
            else if(ADJ[i][j]==4)
                cout<<'|'<<'P'<<'|';                
        }
        cout<<endl;
    }
}