#ifndef _SNAKEMAP_
#define _SNAKEMAP_

#include "Point.h"
#include <vector>

class SnakeMap {
public:
    SnakeMap(const int stage);
    int getTotalStageCount(); // 전체 게임 stage의 개수를 반환한다.
    std::vector<std::vector<int> > getCurrentMap(); // currnet_map을 반환한다.
    int getPositionInfo(const int x, const int y); // current_map[x][y]를 반환한다.
    void setCurrentMap(const int next_stage); // currnet_stage를 next_stage로 set하고, current_map을 totalmap[next_stage]로 변경한다.
    void setPositionInfo(const int x, const int y, const int Info);

private:
    int MAP_WIDTH = 21;
    int MAP_HEIGHT = 21;
    int total_stage_count = 4;
    std::vector<std::vector<std::vector<int> > > total_map;
    int current_stage = 0;
    std::vector<std::vector<int> > current_map;
};

#endif