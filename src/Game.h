#ifndef _GAME_
#define _GAME_

#include <vector>
#include "Snake.h"
#include "GameData.h"
#include "UserData.h"
#include "GateManager.h"
#include "Mission.h"
#include "ItemManager.h"

class Game
{
public :
    bool is_clear;
    bool is_valid;
    int key;

    Game();
    void init(const int stage);
    void setInput();

    void gameStart(const int frame);
    void update(const int frame);
    int isValid();
    bool isClear();
    int getScore();
    void gameEnd();
	
private :
    int game_stage;
    Snake* player;
    GameData* game_data;
    UserData* user_data;
    ItemManager* item_manager;
    Mission* mission;
    GateManager* gate_manager;

    int game_start_frame;

    Renderable* panels[3];
};

#endif