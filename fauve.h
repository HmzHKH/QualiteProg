#ifndef FAUVE_H
#define FAUVE_H

#include "entity.h"
#include "piege.h"

class piegeAPic;
class joueur;

class fauve : public DynamicEntity{
public:
    fauve(const Point& pos);

    Point position() const override;
    bool estVivant() const override;
    virtual void deplacement( AireDeJeu& AdJ, joueur &j,std::vector<std::unique_ptr<fauve>> &fauves, std::vector<piegeAPic> &pieges) = 0;



protected:
    Point d_pos;
    bool d_alive;
};

void killFauve(const Point& p,std::vector<std::unique_ptr<fauve>> &fauves);

//A modifier
void PiegeAPic(const Point& p,std::vector<piegeAPic> &pieges, std::vector<std::unique_ptr<fauve>> &fauves);


// Avance sans diagonales
class lion : public fauve{
public:
    lion(const Point& pos);
    void deplacement( AireDeJeu& AdJ, joueur &j,std::vector<std::unique_ptr<fauve>> &fauves, std::vector<piegeAPic> &pieges) override;
};

// Avance avec diagonales
class tigre : public fauve{
public:
    tigre(const Point& pos);
    void deplacement( AireDeJeu& AdJ, joueur &j,std::vector<std::unique_ptr<fauve>> &fauves, std::vector<piegeAPic> &pieges) override;
};


#endif // FAUVE_H









