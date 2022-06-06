#ifndef _SNAKE_
#define _SNAKE_

#include <vector>
#include "Point.h"
#include "GameData.h"
#include "UserData.h"


class Snake
{
public :

    Snake();

    void update(GameData& game_data, UserData& user_data);
    Point getNextPoint(const int curDir);
    int getSnakeLength() { return bodies.size(); }

private :
    Point next_pos;
    Point head_pos;
    std::vector<Point> bodies;
};

#endif