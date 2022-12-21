#ifndef FAUVE_H
#define FAUVE_H

#include "entity.h"
#include "piege.h"

class piegeAPic;
class joueur;

class fauve : public DynamicEntity{
public:
    fauve(const point& pos);
    point position() const override;
    bool estVivant() const override;
    virtual void deplacement( AireDeJeu& AdJ, joueur &j,std::vector<std::unique_ptr<fauve>> &fauves, std::vector<std::unique_ptr<piegeAPic>> &pieges) = 0;
protected:
    point d_pos;
    bool d_alive;
};

void killFauve(const point& p,std::vector<std::unique_ptr<fauve>> &fauves);

//A modifier
void PiegeAPic(const point& p,std::vector<std::unique_ptr<piegeAPic>> &pieges, std::vector<std::unique_ptr<fauve>> &fauves);


// Avance sans diagonales
class lion : public fauve{
public:
    lion(const point& pos);
    void deplacement( AireDeJeu& AdJ, joueur &j,std::vector<std::unique_ptr<fauve>> &fauves, std::vector<std::unique_ptr<piegeAPic>> &pieges) override;
};

// Avance avec diagonales
class tigre : public fauve{
public:
    tigre(const point& pos);
    void deplacement( AireDeJeu& AdJ, joueur &j,std::vector<std::unique_ptr<fauve>> &fauves, std::vector<std::unique_ptr<piegeAPic>> &pieges) override;
};


#endif // FAUVE_H









