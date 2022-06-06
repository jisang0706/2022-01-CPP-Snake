#ifndef _POINT_
#define _POINT_

#include <iostream>

class Point
{
public:
    int x;
    int y;
    Point() : x(0),y(0) { };
    Point(int x, int y) : x(x), y(y) { };

    friend bool operator==(const Point& x, const Point& y);
    bool isValid();
    Point moveTo(const int curDir);

    Point& operator=(const Point& a);
    friend std::ostream& operator<<(std::ostream& outStream, const Point& point);
};

#endif