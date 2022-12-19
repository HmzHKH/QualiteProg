#include "entity.h"

class fauve : public DynamicEntity{
public:
    virtual ~fauve() = default;
    Point position() const override;
    bool estVivant() const override;
    void killFauve(const Point& p,std::vector<fauve> fauves);
    void PiegeAPic(const Point& p,std::vector<piegeAPic> &pieges, std::vector<fauve> &fauves)
    
protected:
    Point d_pos;
    bool d_alive;
};

// Avance sans diagonales
class lion : public fauve{
public:
    lion();
    void deplacement(const AireDeJeu& AdJ,joueur& j,std::vector<fauve> &fauves, std::vector<piegeAPic> &pieges) override;
};

// Avance avec diagonales
class tigre : public fauve{
public:
    tigre();
    void deplacement(const AireDeJeu& AdJ,joueur& j,std::vector<fauve> &fauves, std::vector<piegeAPic> &pieges) override;
};
