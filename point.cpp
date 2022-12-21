#include "point.h"

point::point(int x, int y):d_x{x},d_y{y}
{}

int point::x() const
{
    return d_x;
}
int point::y() const
{
    return d_y;
}
void point::setx(int x)
{
    d_x = x;
}
void point::sety(int y)
{
    d_y = y;
}