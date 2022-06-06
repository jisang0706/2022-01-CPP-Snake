#ifndef _GAME_MANAGER_
#define _GAME_MANAGER_

#include "GameFlow.h"
#include "Game.h"
#include "GameSettings.h"

class GameManager
{
public :
    GameManager(GameFlow& gameflow);
    void start();
    void end();
    void setInput();
    int isValid();
    void update(const int frame);
private :
    int frame;
    int curStage;
    Game* games;
    Game* curGame;

    GameFlow* game_flow;

    void stageSetting(const int score);
};

#endif