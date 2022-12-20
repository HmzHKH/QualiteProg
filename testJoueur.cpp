#include "doctest.h"
#include "joueur.h"

TEST_CASE("Création d'un joueur Normal")
{
    Point pos{3,4};
    joueurNormal j{pos};
    SUBCASE{"test si le joueur est en vie"}
    {
        bool vie = j.estVivant();
        REQUIRE_UNARY(vie);
    }
    SUBCASE{"test si la position donnée en parametre est celle du joueur"}
    {
        Point position = j.position();
        REQUIRE_EQ(pos.x, position.x);
        REQUIRE_EQ(pos.y, position.y);
    }
}

TEST_CASE("Création d'un joueur Expert")
{
    Point pos{3,4};
    joueurExpert j{pos};
    SUBCASE{"test si le joueur est en vie"}
    {
        bool vie = j.estVivant();
        REQUIRE_UNARY(vie);
    }
    SUBCASE{"test si la position donnée en parametre est celle du joueur"}
    {
        Point position = j.position();
        REQUIRE_EQ(pos.x, position.x);
        REQUIRE_EQ(pos.y, position.y);
    }
}
TEST_CASE("Test le temps de survie du joueur")
{
    joueur j;
    int lifetime = j.lifetime();
    REQUIRE_EQ(lifetime,j.lifetime());
}

TEST_CASE("Test l'état du joueur")
{
    joueur j;
    bool alive = true;
    REQUIRE_EQ(alive,j.estVivant());
}

TEST_CASE("Test si le joueur meurt")
{
    joueur j;
    bool dead = false;
    j.setDeath();
    REQUIRE_EQ(dead,j.estVivant());
}

TEST_CASE("Test si le joueur meurt")
{
    std::unique_ptr<joueur> j;
    bool dead = false;
    j->setDeath();
    REQUIRE_EQ(dead,j->estVivant());
}

TEST_CASE("Test si la position du joueur")
{
    joueur j;
    Point pos = j.position();
    REQUIRE_EQ(pos,j.position());
}

//FAIRE DEPLACEMENT JOUEURNORMAL ET JOUEUREXPERT