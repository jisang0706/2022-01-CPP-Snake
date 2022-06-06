#ifndef _GATEMANAGER_
#define _GATEMANAGER_

#include <vector>
#include <ctime>
#include <cstdlib>
#include "Point.h"
#include "GameData.h"
#include "GameSettings.h"
#include "UserData.h"

class GateManager
{
private:
    const int GATE_MANAGER_IMMUNE_WALL=-2;
    std::pair<Point, Point> gates;
    std::pair<std::vector<int>, std::vector<int> > gate_directions;
    bool is_passing = false; // 뱀이 통과중인가?
    int live_time=5;  // 게이트 생존시간 처리용
    int snake_entered_frame = -2100000000; // 뱀이 게이트에 처음 들어간 프레임
    int last_gate_deleted_frame = 1; // 게이트가 삭제된 프레임
    int wall_map[MAP_X][MAP_Y]={0,};
    std::vector<Point> wall_list[100];
    int check_wall[MAP_X * MAP_Y] = {0,};
    int wall_count=0;
    bool isExist = false;
    
    const int DIR_PRIORITY_TABLE[5][5]={
        {DIR_UP,DIR_RIGHT,DIR_LEFT,DIR_DOWN},
        {DIR_DOWN, DIR_LEFT, DIR_RIGHT, DIR_UP},
        {DIR_RIGHT, DIR_DOWN, DIR_UP, DIR_LEFT},
        {DIR_LEFT, DIR_UP, DIR_DOWN, DIR_RIGHT},
    };
    
    int dx[4] = {-1,1,0,0};
    int dy[4] = {0,0,-1,1};
    
    void makeWallMap(const int num, const int x, const int y);
    std::vector<int> makeGateDirection(Point gate);

public:
    GateManager(const std::vector<std::vector<int> > snake_map);
    void makeNewGate();
    void update(GameData &game_data, UserData &user_data);
    std::pair<Point, Point> getGates();
};

#endif