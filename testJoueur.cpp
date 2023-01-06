#include "doctest.h"
#include "joueur.h"

TEST_CASE("Création d'un joueur Normal")
{
    point pos{3,4};
    joueurNormal j{pos};
    SUBCASE("test si le joueur est en vie")
    {
        bool vie = j.estVivant();
        REQUIRE_UNARY(vie);
    }
    SUBCASE("test si la position donnée en parametre est celle du joueur")
    {
        point position = j.position();
        REQUIRE_EQ(pos, position);
    }
}

TEST_CASE("Création d'un joueur Expert")
{
    point pos{3,4};
    joueurExpert j{pos};
    SUBCASE("test si le joueur est en vie")
    {
        bool vie = j.estVivant();
        REQUIRE_UNARY(vie);
    }
    SUBCASE("test si la position donnée en parametre est celle du joueur")
    {
        point position = j.position();
        REQUIRE_EQ(pos, position);
    }
}
TEST_CASE("Test le temps de survie du joueur")
{
    point pos{2,1};
    joueurNormal j(pos);
    int lifetime = j.lifetime();
    REQUIRE_EQ(lifetime,j.lifetime());
}

TEST_CASE("Test l'état du joueur")
{
    point pos{2,1};
    joueurNormal j(pos);
    bool alive = true;
    REQUIRE_EQ(alive,j.estVivant());
}

TEST_CASE("Test si le joueur meurt")
{
    point pos{2,1};
    joueurNormal j(pos);
    bool dead = false;
    j.setDeath();
    REQUIRE_EQ(dead,j.estVivant());
}

TEST_CASE("Test si le joueur meurt")
{
    point pos{2,1};
    joueurNormal j(pos);
    bool dead = false;
    j.setDeath();
    REQUIRE_EQ(dead,j.estVivant());
}

TEST_CASE("Test  la position du joueur")
{
    point pos{2,1};
    joueurNormal j(pos);
    point pos1 = j.position();
    REQUIRE_EQ(pos1,j.position());
}



//TEST DEPLACEMENT JOUEURNORMAL ET JOUEUREXPERT


TEST_CASE("Test le deplacement d'un joueur dans l'aire de jeu")
{
    AireDeJeu Adj{5,5};

    point pos{2,2};

    std::vector<std::unique_ptr<joueur>> joueurs;
    SUBCASE("Test deplacement joueur normal")
    {

        joueurs.push_back(std::make_unique<joueurNormal>(pos));
        Adj.setValue(pos,1);

        SUBCASE("tester le deplacement vers le haut")
        {
            pos.setx(1);
            joueurs[0]->deplacement(Adj,8);
            REQUIRE_EQ(joueurs[0]->position(),pos);

        }
        SUBCASE("tester le deplacement vers le bas")
        {
            pos.setx(3);
            joueurs[0]->deplacement(Adj,2);
            REQUIRE_EQ(joueurs[0]->position(),pos);

        }
        SUBCASE("tester le deplacement vers la gauche")
        {
            pos.sety(1);
            joueurs[0]->deplacement(Adj,4);
            REQUIRE_EQ(joueurs[0]->position(),pos);

        }
        SUBCASE("tester le deplacement vers la droite")
        {
            pos.sety(3);
            joueurs[0]->deplacement(Adj,6);
            REQUIRE_EQ(joueurs[0]->position(),pos);

        }
        SUBCASE("tester le deplacement vers le haut droite")
        {
            pos.setx(1);
            pos.sety(3);
            joueurs[0]->deplacement(Adj,9);
            REQUIRE_EQ(joueurs[0]->position(),pos);

        }
        SUBCASE("tester le deplacement vers le haut gauche")
        {
            pos.setx(1);
            pos.sety(1);
            joueurs[0]->deplacement(Adj,7);
            REQUIRE_EQ(joueurs[0]->position(),pos);

        }
        SUBCASE("tester le deplacement vers le bas gauche")
        {
            pos.setx(3);
            pos.sety(1);
            joueurs[0]->deplacement(Adj,1);
            REQUIRE_EQ(joueurs[0]->position(),pos);

        }
        SUBCASE("tester le deplacement vers le bas droite")
        {
            pos.setx(3);
            pos.sety(3);
            joueurs[0]->deplacement(Adj,3);
            REQUIRE_EQ(joueurs[0]->position(),pos);

        }


    }

    SUBCASE("Test deplacement joueur expert")
    {
        joueurs.push_back(std::make_unique<joueurExpert>(pos));
        Adj.setValue(pos,1);




        SUBCASE("tester le deplacement vers le haut")
        {
            pos.setx(1);
            joueurs[0]->deplacement(Adj,8);
            REQUIRE_EQ(joueurs[0]->position(),pos);

        }
        SUBCASE("tester le deplacement vers le bas")
        {
            pos.setx(3);
            joueurs[0]->deplacement(Adj,2);
            REQUIRE_EQ(joueurs[0]->position(),pos);

        }
        SUBCASE("tester le deplacement vers la gauche")
        {
            pos.sety(1);
            joueurs[0]->deplacement(Adj,4);
            REQUIRE_EQ(joueurs[0]->position(),pos);

        }
        SUBCASE("tester le deplacement vers la droite")
        {
            pos.sety(3);
            joueurs[0]->deplacement(Adj,6);
            REQUIRE_EQ(joueurs[0]->position(),pos);

        }



    }

}
