#ifndef _GAME_SETTINGS_
#define _GAME_SETTINGS_

#define MAX_STAGE 4
#define MAP_X 21
#define MAP_Y 21

// 키보드 입력 상수
#define KB_UP 259
#define KB_DOWN 258
#define KB_RIGHT 261
#define KB_LEFT 260

#define KB_BACKSPACE 263
#define KB_ENTER 10

#define KB_W 119
#define KB_S 115
#define KB_D 100
#define KB_A 97


// 뱀 방향
#define DIR_UP 0
#define DIR_DOWN 1
#define DIR_RIGHT 2
#define DIR_LEFT 3

// 맵에 그릴 정보
#define EMPTY 0
#define SNAKE_HEAD 1
#define SNAKE_BODY 2
#define WALL 3
#define IMMUNE_WALL 4
#define GATE 5
#define GROWTH_ITEM 6 
#define POSTION_ITEM 7

#endif