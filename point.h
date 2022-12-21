#ifndef POINT_H
#define POINT_H

class point{
public:
    point(int x, int y);
    int x() const;
    int y() const;
    void setx(int x);
    void sety(int y);
private:
    int d_x;
    int d_y;
};

#endif // POINT_H