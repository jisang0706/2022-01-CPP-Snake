#ifndef _ITEMMANAGER_
#define _ITEMMANAGER_
#include "Item.h"
#include "Point.h"
#include "UserData.h"
#include "GameData.h"
#include <vector>

class ItemManager{

public:
    ItemManager();
    void makeItem(int current_frame, const std::vector<std::vector<int> >& map, GameData &game_data);
    int eatItem(const Point& next_head_point, GameData &game_data);
    void deleteItem(const int current_frame, GameData &game_data);
    void update(GameData &game_data, UserData &user_data);
    std::vector<Item> items;

private:
    int last_made_frame;
    int delay;
    int growth_odd;
    int disappear_frame;
};

#endif