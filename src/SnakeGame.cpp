#include <ncurses.h>
#include <unistd.h>

#include "GameManager.h"
#include "NcursesSetting.h"
#include "GameFlow.h"


int main(void)
{
  NcursesSetting();
  GameFlow game_flow;
  GameManager game_manager(game_flow);

  // 시작메뉴
  while(1)
  {
    int game_status = game_flow.renderStartMenu();
    if(game_status == 0) 
    {
      break;
    }
    else if(game_status == 1) 
    {
      game_flow.renderAbout();
    }
    else
    {
      game_flow.renderMakers();
      endwin();
      return 0;
    }
  }

  // 게임 실행
  game_manager.start();

  int frame = 1;
  int timer = 100;
  while(1)
  {
    timer++;
    // 키보드 입력검사는 0.05초마다
    game_manager.setInput();

    // 게임업데이트는 0.25초
    if(timer > 40)
    {
      // 유효성 검사
      if(game_manager.isValid())
      {
        game_manager.update(frame++);  // 각종 게임 정보들 업데이트
      }
      else
      {
        game_manager.end();
        break;
      }
      timer = 0;
    }

    usleep(5000);
  }

  game_flow.renderGameEnd();  // 종료 시 보여줄 화면
  game_flow.renderMakers();   // 크레딧

  endwin();

  return 0;
}
 