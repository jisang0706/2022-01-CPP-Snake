#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include "Item.h"
#include "Point.h"
#include "ItemManager.h"
#include "GameSettings.h"

struct ItemPortion {
    Point p;
    int weight;

    bool operator<(const ItemPortion B) const{
        return weight > B.weight;
    }
};

ItemManager::ItemManager(){
    last_made_frame = 0;
    delay = 8;
    growth_odd = 6;
    disappear_frame = 40;
    items = {};
}

void ItemManager::makeItem(int current_frame, const std::vector<std::vector<int> >& map, GameData &game_data){
    if(items.size() < 3 && current_frame >= last_made_frame + delay)
    {   
        Point mo_create_location = Point(1,1);
        int create_x, create_y;

        std::vector <ItemPortion> temp_portion;
        for(int x=0; x<game_data.sq; x++) {
            for(int y=0; y<game_data.sq; y++) {
                if(game_data.mo_count[x][y] > 0) {
                    temp_portion.push_back({Point(x,y), game_data.mo_count[x][y]});
                }
            }
        }

        if(temp_portion.empty()) {
            return;
        }

        sort(temp_portion.begin(), temp_portion.end());

        mo_create_location = temp_portion[rand() % (temp_portion.size()>3?3:temp_portion.size())].p;

        int rand_x,rand_y,temp;

        do {
            int rand_number = (rand() % (game_data.mo_points[mo_create_location.x * game_data.sq + mo_create_location.y].size()));
            rand_x = game_data.mo_points[mo_create_location.x * game_data.sq + mo_create_location.y][rand_number].x;
            rand_y = game_data.mo_points[mo_create_location.x * game_data.sq + mo_create_location.y][rand_number].y;
        }
        while(rand_x > 0 && rand_y > 0 && rand_x < MAP_X && rand_y < MAP_Y && map[rand_x][rand_y] != 0);

        Point create_location = Point(rand_x, rand_y);
        last_made_frame = current_frame;

        temp = rand()%10;
        int kind;
        if(temp<=growth_odd){
            kind = 1;
        }else{
            kind = 2;
        }

        game_data.mo_count[rand_x/game_data.sq][rand_y/game_data.sq] -=3;
        
        items.push_back(Item(create_location, kind, current_frame));
    }    
}

int ItemManager::eatItem(const Point& next_head_point, GameData &game_data){
    for(int i = 0; i<items.size(); i++){
        if(items.at(i).getPos() == next_head_point) {
            game_data.mo_count[items.at(i).getPos().x/game_data.sq][items.at(i).getPos().y/game_data.sq]+=3;
            if(items.at(i).getKinds() == 1){
                items.erase(items.begin()+i);
                return 1;
            }        
            else{
                items.erase(items.begin()+i);
                return 2;
            }
        }       
    }
    return 0;
}
void ItemManager::deleteItem(const int current_frame, GameData &game_data){
    for(int i = 0; i<items.size(); i++){
        if(items.at(i).getCreatedframe() + disappear_frame <= current_frame ){
            game_data.setPositionInfo(items.at(i).getPos().x, items.at(i).getPos().y, 0);
            game_data.mo_count[items.at(i).getPos().x/game_data.sq][items.at(i).getPos().y/game_data.sq]+=3;
            items.erase(items.begin()+i);
        }
    }
}

void ItemManager::update(GameData &game_data, UserData &user_data){

    int current_frame = game_data.getCurrentframe();
    Point next_head_point = game_data.getNextHeadPoint();
    std::vector<std::vector<int> > map = game_data.getMap();

    makeItem(current_frame, map, game_data);
    deleteItem(current_frame, game_data);
    switch(eatItem(next_head_point, game_data))
    {
        case 0:
            break;
        case 1:
            user_data.growthItemIncrease();
            break;
        case 2:
            user_data.poisonItemIncrease();
            break;
    }

    std::vector<Point> items_pos = {};
    std::vector<int> items_type = {};

    for(int i = 0; i<items.size(); i++){
        items_pos.push_back(items.at(i).getPos());
        items_type.push_back(items.at(i).getKinds());
    }

    game_data.updateItemPosition(items_pos, items_type);
}