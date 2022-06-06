#ifndef _GAME_FLOW_
#define _GAME_FLOW_

#include <ncurses.h>
#include <string>
#include <vector>

class GameFlow
{
public :
    GameFlow();

    int renderStartMenu();
    void renderMakers();
    void renderAbout();
    void renderGameEnd();

    int renderStageEnter(const int stage); // 게임 진입 시
    int renderStageClear(const int stage, const int score); // 클리어 시
    void setStageScore(int stage, int score);

private :
    char text[400] = "      제작자\n\n\n  20213057 이제준\n\n  20213060 이지상\n\n   Press Any Key";
    std::vector<int> scores = {0, 0, 0, 0};
    std::string explain[17] = 
    {
        "                                                        ",
        "", 
        "              ★  는 길이 증가 아이템입니다", 
        "              ☆  는 길이 감소 아이템입니다", 
        "", 
        "                방향키는 W A S D 입니다", 
        "               ▦ 모양은 게이트 입니다", 
        "           통과하면 반대편 게이트로 나올 수 있어요", 
        "", 
        "                오른쪽에 미션이 있습니다", 
        "                잘 확인하고 클리어하세요", 
        "",
        "                  총 4스테이지입니다", 
        "                     화이팅하세요", 
        ""
    };

    void eraseWindow(WINDOW* window);

};

#endif
