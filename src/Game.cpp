#include "Game.h"
#include "GameSettings.h"

Game::Game()
{
    is_clear = false;
    is_valid = true;
    key = 0;
}

// 게임별 맵 저장, 게임매니저 생성자에서 각각 호출
void Game::init(const int stage)
{
    game_stage = stage;
    player = new Snake();
    game_data = new GameData(stage);
    user_data = new UserData();
    item_manager = new ItemManager();
    mission = new Mission(stage);
    gate_manager = new GateManager(game_data -> getMap());

    panels[0] = game_data;
    panels[1] = user_data;
    panels[2] = mission;
}

void Game::setInput()
{
    if(!is_valid) return;

    game_data -> updateDirection();
    key = game_data -> getKey();
}

void Game::gameStart(const int frame)
{
    my_start_frame = frame - 1;
}


// 매프레임 게임 유효성 검사
int Game::isValid()
{
    if(!is_valid) return is_valid;

    Point next = player -> getNextPoint(game_data -> getCurrentDirection());
    game_data -> setNextPoint(next);
    game_data -> setNextHeadPoint(next);

    switch (game_data -> getPositionInfo(next.x, next.y))
    {
    case WALL : // 벽에 닿았을 때
    case SNAKE_BODY : // 자기 몸통
    case SNAKE_HEAD : // 헤드 //
        is_valid = false;
        break;
    case POSTION_ITEM : // 감소 아이템
        if(player->getSnakeLength() <= 3)
        {
            is_valid = false;
        }
        break;
    default:
        break;
    }

    if(key == KB_BACKSPACE)  // 백스페이스 누를 경우
    {
        is_valid = false;
    }
    
    if(is_valid == false) gameEnd();
    return is_valid;   
}

// 매 프레임 유효성 검사되면 모든 정보 추합해서 맵에 저장해야함
void Game::update(const int frame)
{
    game_data -> mapReset();   
    game_data -> setCurrentFrame(frame - my_start_frame);
    user_data -> setCurrentFrame(frame - my_start_frame);
    
    player -> update(*game_data, *user_data);
    item_manager -> update(*game_data, *user_data);
    gate_manager -> update(*game_data, *user_data);

    for(int i = 0 ; i < 3 ; i++)
    {
        panels[i] -> render();
    }
}


// Update 끝마친 후 호출
bool Game::isClear()
{
    if(key == 98)
    {
        is_clear = true;
    }

    // 여기에서 mission 클리어 판단
    if(mission -> isComplete(*user_data))
    {
        is_clear = true;
    }

    return is_clear;
}

int Game::getScore()
{
    return user_data->getScore();
}

void Game::gameEnd()
{
    delete player;
    delete game_data;
    delete user_data;
    delete gate_manager;
    delete item_manager;
    delete mission;
}