#include "doctest.h"
#include "fauve.h"
#include "piege.h"

TEST_CASE("test sur la creation d'un lion")
{
    Point pos{5,4};
    lion l{pos,true};
    SUBCASE("test si le lion est en vie")
    {
        bool vie = l.estVivant();
        REQUIRE_UNARY(vie);     //test si d_alive = true
    }
    SUBCASE("test si le lion est cree a la position donnee en parametre")
    {
        Point position = l.position();
        REQUIRE_EQ(pos.x, position.x);    //test si la position est correcte
        REQUIRE_EQ(pos.y, position.y);
    }
}

TEST_CASE("test sur la creation d'un tigre")
{
    Point pos{5,4};
    tigre t{pos,true};
    SUBCASE("test si le tigre est en vie")
    {
        bool vie = t.estVivant();
        REQUIRE_UNARY(vie);     //test si d_alive = true
    }
    SUBCASE("test si le tigre est cree a la position donnee en parametre")
    {
        Point position = t.position();
        REQUIRE_EQ(pos.x, position.x);    //test si la position est correcte
        REQUIRE_EQ(pos.y, position.y);
    }
}

TEST_CASE("test tableau de fauve")
{
    std::vector<fauve> fauves;
    Point pos1{5,4};
    lion lion1{pos,true};
    fauves.push_back(lion1);
    Point pos2{4,4};
    lion lion2{pos,true};
    fauves.push_back(lion2);
    Point pos3{4,3};
    tigre tigre1{pos,true};
    fauves.push_back(tigre1);

    std::vector<piegeAPic> &pieges;
    Point posp{5,4};
    int t = 3;
    piegeAPic p{posp,t};

    SUBCASE("test si on tue un fauve")
    {
        int taille1 = fauves.size();
        killFauve(pos2,fauves);
        int taille2 = fauves.size();
        REQUIRE_LT(taille2,taille1)  //test si taille2 < taille1 et donc qu'on a tuer un fauve
    }
    SUBCASE("test si le piege tue un fauve et que sa taille diminue")
    {
        int taille1 = fauves.size();
        int nb1 = p.taille();
        PiegeAPic(pos1,pieges,fauves);
        int taille2 = fauves.size();
        int nb2 = p.taille();
        REQUIRE_LT(taille2,taille1);  //test si taille2 < taille1 et donc qu'on a tuer un fauve
        REQUIRE_LT(nb2,nb1);      //test si la taille du piege diminue
    }
}
