#ifndef _MISSION_
#define _MISSION_
#include "UserData.h"
#include "Renderable.h"
#include <vector>

class Mission : public Renderable
{
public:
    Mission(const int stage);
    bool isComplete(UserData &user_data);
    void render();

private:
    std::vector<bool> current_mission_state;
    std::vector<int> current_mission_list;
    std::vector<std::vector<int> > total_mission_list;
    std::vector<int> current_state;
};

#endif