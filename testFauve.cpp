#include "doctest.h"
#include "fauve.h"
#include "piege.h"

TEST_CASE("test sur la creation d'un lion")
{
    point pos{5,4};
    lion l{pos};
    SUBCASE("test si le lion est en vie")
    {
        bool vie = l.estVivant();
        REQUIRE_UNARY(vie);     //test si d_alive = true
    }
    SUBCASE("test si le lion est cree a la position donnee en parametre")
    {
        point position = l.position();
        REQUIRE_EQ(pos, position);    //test si la position est correcte
    }
}

TEST_CASE("test sur la creation d'un tigre")
{
    point pos{5,4};
    tigre t{pos};
    SUBCASE("test si le tigre est en vie")
    {
        bool vie = t.estVivant();
        REQUIRE_UNARY(vie);     //test si d_alive = true
    }
    SUBCASE("test si le tigre est cree a la position donnee en parametre")
    {
        point position = t.position();
        REQUIRE_EQ(pos, position);    //test si la position est correcte
    }
}
//A corriger
/*
TEST_CASE("test tableau de fauve")
{
    std::vector<std::unique_ptr<fauve>>fauves;
    point pos1{5,4};
    fauves.push_back(std::make_unique<lion>(pos1));


    point pos2{4,4};
    fauves.push_back(std::make_unique<lion>(pos2));

    point pos3{4,3};
    fauves.push_back(std::make_unique<lion>(pos3));


    std::vector<std::unique_ptr<piegeAPic>> pieges;
    point posp{5,4};
    int t = 3;
    pieges.push_back(std::make_unique<piegeAPic>(posp,t));

    SUBCASE("test si on tue un fauve")
    {
        int taille1 = fauves.size();
        killFauve(pos2,fauves);

        int taille2 = fauves.size();
        REQUIRE_LT(taille2,taille1);  //test si taille2 < taille1 et donc qu'on a tuer un fauve
    }
    SUBCASE("test si le piege tue un fauve et que sa taille diminue")
    {
        int taille1 = fauves.size();
        int nb1 = pieges[0]->taille();
        killPiegeAPic(pos1,pieges,fauves);
        int taille2 = fauves.size();
        int nb2 = pieges[0]->taille();
        REQUIRE_LT(taille2,taille1);  //test si taille2 < taille1 et donc qu'on a tuer un fauve
        REQUIRE_LT(nb2,nb1);      //test si la taille du piege diminue
    }
}
*/
