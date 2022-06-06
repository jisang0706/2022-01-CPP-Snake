#include "Point.h"
#include "GameSettings.h"

Point& Point::operator=(const Point& a)
{
    x = a.x;
    y = a.y;
    return (*this);
}

bool operator==(const Point& x, const Point& y)
{
    return (x.x == y.x) && (x.y == y.y);
}

bool Point::isValid()
{
    return (*this).x>=0 && (*this).y>=0 && (*this).x < MAP_X && (*this).y < MAP_Y;
}


// todo: point.moveTo()로 호출할 것
Point Point::moveTo(const int curDir)
{
    int x = (*this).x;
    int y = (*this).y;

    switch (curDir)
    {
        case DIR_UP : // 위쪽
            x--;
            break;
        case DIR_DOWN : // 아래쪽
            x++;
            break;
        case DIR_RIGHT : // 오른쪽
            y++;
            break;
        case DIR_LEFT : // 왼쪽
            y--;
            break;
    }
    return Point(x,y);
}

std::ostream& operator<<(std::ostream& outStream, const Point& point)
{
    outStream << "(" << point.x << "," << point.y << ")" << '\n';
    return outStream;
}