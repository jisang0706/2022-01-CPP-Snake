#ifndef _GAME_FLOW_
#define _GAME_FLOW_

#include <ncurses.h>
#include <string>
#include <vector>

class GameFlow
{
public :
    GameFlow();

    int InfoStartMenu();
    void InfoMakers();
    void InfoAbout();
    void InfoGameEnd();

    int InfoStageEnter(const int stage); // 게임 진입 시
    int InfoStageClear(const int stage, const int score); // 클리어 시
    void setStageScore(int stage, int score);

private :
    char text[400] = "      제작자\n\n\n  20213057 이제준\n\n  20213060 이지상\n\n   Press Any Key";
    std::vector<int> scores = {0, 0, 0, 0};
    std::string explain[17] = 
    {
        "                                                        ",
        "", 
        "                 ★ - 몸통 길이 증가 아이템", 
        "                 ☆ - 몸통 길이 감소 아이템", 
        "", 
        "                  방향키는 W A S D 입니다", 
        "                       ▩ - 게이트", 
        "            통과하면 반대편 게이트로 나올 수 있습니다", 
        "", 
        "                   오른쪽에 미션이 있습니다", 
        "                   잘 확인하고 클리어하세요", 
        "",
        "                     총 4스테이지입니다", 
        "",
        ""
    };

    void eraseWindow(WINDOW* window);

};

#endif
