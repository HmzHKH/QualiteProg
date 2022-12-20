#include "entity.h"

class piege : public StaticEntity
{
public:
    virtual ~piege() = default;
};

class piegeAPic : public piege
{
public:
    piegeAPic(const Point& pos, int taille);
    Point position() const override;
    bool estActif() const override;
    int taille() const;
    void increaseTaille();
private:
    Point d_pos;
    bool d_actif;
    int d_taille;
}
