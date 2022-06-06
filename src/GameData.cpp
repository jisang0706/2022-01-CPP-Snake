#include "GameData.h"
#include "GameSettings.h"
#include "kbhit.h"

GameData::GameData(const int stage)
{
    current_direction = 0;
    snake_map = new SnakeMap(stage);
    sq = 5;
    mo_count.resize(sq+1);
    mo_points.resize((sq+1)*(sq+1));

    for(int x = 0; x < sq +1; x++) {
        for(int y=0; y <sq +1; y++) {
            mo_count[x].push_back(0);
        }
    }

    for(int x=0; x<MAP_X; x++) {
        for(int y=0; y<MAP_Y; y++) {
            if(snake_map->getPositionInfo(x,y) == EMPTY) {
                mo_count[x/sq][y/sq]++;
                mo_points[(x/sq)*sq + (y/sq)].push_back(Point(x, y));
            }
            else if(snake_map->getPositionInfo(x,y) == WALL) {
                mo_count[x/sq][y/sq]++;
            }
        }
    }
    
    mo_count[17/sq][10/sq]-=1;
    mo_count[18/sq][10/sq]-=1;
    mo_count[19/sq][10/sq]-=1;

    window = newwin(MAP_Y, MAP_X * 2, 1, 1);
    keypad(window, TRUE);
}

void GameData::update(const int current_frame)
{
    this->current_frame = current_frame;
}

int GameData::checkItem(const Point& head)
{
    int info = snake_map->getPositionInfo(head.x, head.y);
    if (info == 6)
        return 1;
    if (info == 7)
        return -1;
    return 0;
}

std::vector<std::vector<int> > GameData::getMap()
{
    return snake_map->getCurrentMap();
}

void GameData::setNextPoint(const Point& next_point)
{
    this->next_point = next_point;
}

void GameData::setNextHeadPoint(const Point& next_head_point)
{
    this->next_head_point = next_head_point;
}

Point GameData::getNextPoint()
{
    return next_point;
}

Point GameData::getNextHeadPoint()
{
    return next_head_point;
}

void GameData::setCurrentframe(const int current_frame)
{
    this->current_frame = current_frame;
}

int GameData::getCurrentframe()
{
    return current_frame;
}

// 키값 입력될때마다 방향 변경해줌

void GameData::updateDirection()
{
    if (kbhit())
    {
        key = wgetch(window);
        switch (key)
        {
        case KB_W:  // w
        case KB_UP: // 위
            current_direction = DIR_UP;
            break;
        case KB_S:    // s
        case KB_DOWN: // 아래
            current_direction = DIR_DOWN;
            break;
        case KB_RIGHT: // d
        case KB_D:     // 오른
            current_direction = DIR_RIGHT;
            break;
        case KB_A:    // a
        case KB_LEFT: // 왼
            current_direction = DIR_LEFT;
            break;
        default:
            break;
        }
    }
}

void GameData::render()
{
    std::vector<std::vector<int> > canvas = snake_map->getCurrentMap();
    wclear(window);
    for (int i = 0; i < canvas.size(); i++)
    {
        for (int j = 0; j < canvas[i].size(); j++)
        {
            wprintw(window, " ");
            mvwprintw(window, i, 2*j, "%lc", changeMap(canvas[i][j]));
        }
    }
    wrefresh(window);
}

wchar_t GameData::changeMap(const int i)
{
    wchar_t temp;
    switch (i)
    {
    case EMPTY:
        temp = L'\u200b';
        break;
    case SNAKE_HEAD:
        switch(current_direction)
        {
            case DIR_UP:
                temp = L'▲';
                break;
            case DIR_DOWN:
                temp = L'▼';
                break;
            case DIR_RIGHT:
                temp = L'▶';
                break;
            case DIR_LEFT:
                temp = L'◀';
                break;
        }
        break;
    case SNAKE_BODY:
        temp = L'◎';
        break;
    case WALL:
    case IMMUNE_WALL:
        temp = L'■';
        break;
    case GATE:
        temp = L'▦';
        break;
    case GROWTH_ITEM:
        temp = L'★';
        break;
    case POSTION_ITEM:
        temp = L'☆';
        break;
    default:
        temp = L'?';
        break;
    }
    return temp;
}

void GameData::updateItemPosition(const std::vector<Point>& item_positions, const std::vector<int>& item_infos)
{
    for (int i = 0; i < item_positions.size(); i++)
    {
        snake_map->setPositionInfo(item_positions[i].x, item_positions[i].y, item_infos[i] + 5);
    }
}

void GameData::updateSnakePosition(const std::vector<Point>& snake_body)
{
    snake_map->setPositionInfo(snake_body[0].x, snake_body[0].y, 1);
    for (int i = 1; i < snake_body.size(); i++)
    {
        snake_map->setPositionInfo(snake_body[i].x, snake_body[i].y, 2);
    }
}

void GameData::updateGatePosition(bool isExist, const std::vector<Point>& gates)
{
    if (isExist)
    {
        for (int i = 0; i < this->gates.size(); i++)
        {
            snake_map->setPositionInfo(this->gates[i].x, this->gates[i].y, WALL);
        }

        for (int i = 0; i < gates.size(); i++)
        {
            snake_map->setPositionInfo(gates[i].x, gates[i].y, GATE);
        }
        this->gates = gates;
    }
    else
    {
        for (int i = 0; i < this->gates.size(); i++)
        {
            snake_map->setPositionInfo(this->gates[i].x, this->gates[i].y, WALL);
        }
        this->gates.clear();
    }
}

void GameData::updateGateDirection(bool isExist, const std::vector<std::vector<int> >& gate_directions)
{
    if (isExist)
    {
        this->gate_directions = gate_directions;
    }
    else
    {
        this->gate_directions.clear();
    }
}

std::vector<Point> GameData::getGatePositions()
{
    return gates;
}

std::vector<std::vector<int> > GameData::getGateDirections()
{
    return gate_directions;
}

int GameData::getCurrentDirection()
{
    return current_direction;
}

void GameData::setCurrentDirection(const int current_direction)
{
    this->current_direction = current_direction;
}

void GameData::mapReset()
{
    for (int i = 0; i < 21; i++)
    {
        for (int j = 0; j < 21; j++)
        {
            if (snake_map->getPositionInfo(i, j) == 1 || snake_map->getPositionInfo(i, j) == 2)
            {
                snake_map->setPositionInfo(i, j, 0);
            }
        }
    }
}

int GameData::getPositionInfo(const int x, const int y)
{
    return snake_map->getPositionInfo(x, y);
}

void GameData::setPositionInfo(const int x, const int y, const int info)
{
    return snake_map->setPositionInfo(x, y, info);
}