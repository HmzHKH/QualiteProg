#include"doctest.h"
#include"AireDeJeu.h"
/*
TEST_CASE("Création de aire de jeu")
{
    point p{5,6};
    AireDeJeu aire{10,15};
    int e = 3;

    SUBCASE("Tester si un point est dans le tableau ")
    {
        bool present = aire.estDansTableau(p);
        REQUIRE_UNARY(present);
    }

    SUBCASE("Tester si une case est libre")
    {
        bool libre = aire.estLibre(p);
        REQUIRE_UNARY(libre);
    }

    SUBCASE("Renvoie si un type d'entite occupe une position donnee")
    {
        bool occupe = true;
        REQUIRE_EQ(occupe,aire.estOccupeType(e,p));
    }
/*
    SUBCASE("Tester la position du joueur")
    {
        point pos1 = aire.position();
        REQUIRE_EQ(pos1,aire.position());
    }

}
*/
