#include "UserData.h"
#include "GameSettings.h"

UserData::UserData()
{
    current_length = 3;
    max_length = 3;
    growth_item_count = 0;
    poison_item_count = 0;
    used_gate_count = 0;

    window = newwin((MAP_Y + 1) / 2 - 1, MAP_X, 1, 44);
}

int UserData::getCurrentLength() {//현재 길이 반환
    return current_length;
}
void UserData::setCurrentLength(const int current_length) { //현재 길이 설정
    this->current_length = current_length;
    UserData::setMaxLength(current_length);
}
int UserData::getMaxLength() { //최대 길이 반환
    return max_length;
}
void UserData::setMaxLength(const int current_length) { //최대 길이 설정
    if (current_length > max_length) max_length = current_length;
}

int UserData::getGrowthItemCount() { //성장아이템 먹은 횟수 반환
    return growth_item_count;
}
void UserData::setGrowthItemCount(const int growth_item_count) { //성장아이템 먹은 횟수 설정
    this->growth_item_count = growth_item_count;
}


int UserData::getPoisonItemCount() { //감소아이템 먹은 횟수 반환
    return poison_item_count;
}
void UserData::setPoisonItemCount(const int poison_item_count) { //감소아이템 먹은 횟수 설정
    this->poison_item_count = poison_item_count;

}

void UserData::growthItemIncrease() { //성장아이템 먹은 횟수+1
    //this->growth_item_count = growth_item_count;
    growth_item_count++;
}

void UserData::poisonItemIncrease() { //감소아이템 먹은 횟수+1
    //this->poison_item_count = poison_item_count;
    poison_item_count++;
}


int UserData::getUsedGateCount() { //게이트를 사용한 횟수 반환
    return used_gate_count;
}


void UserData::setUsedGateCount(const int used_gate_count) { //게이트를 사용한 횟수 설정
    this->used_gate_count = used_gate_count;
};

void UserData::usedGateCountIncrease() { //게이트를 사용한 횟수+1
    this->used_gate_count = used_gate_count;
    used_gate_count++;
}

int UserData::getScore() {
    return max_length*10 + growth_item_count*5 + poison_item_count*5 + used_gate_count*20 + current_frame;
}

void UserData::setCurrentFrame(int current_frame) {
    this->current_frame = current_frame;
}

void UserData::render() {
    wborder(window, ACS_VLINE, ACS_VLINE, ACS_HLINE, ACS_HLINE, ACS_ULCORNER, ACS_URCORNER, ACS_LLCORNER, ACS_LRCORNER);
    mvwprintw(window, 1, 1, "----SCORE BOARD----");
    mvwprintw(window, 3, 1, "Score : %d", UserData::getScore());
    mvwprintw(window, 4, 1, "B : %d / %d", current_length, max_length);
    mvwprintw(window, 5, 1, "+ : %d", growth_item_count);
    mvwprintw(window, 6, 1, "- : %d", poison_item_count);
    mvwprintw(window, 7, 1, "G : %d", used_gate_count);
    wrefresh(window);
}