#ifndef _ITEM_
#define _ITEM_

#include "Point.h"

class Item{
private:
    Point pos; //아이템의 위치(position)
	int kinds; //아이템의 종류 (1:grwoth 2:poison)
	int created_frame; //아이템 생성 시기
public:
	Item();
    Item(const Point pos, const int kinds, const int frame);
    Point getPos();
    int getKinds();
    int getCreatedframe();
    void setPos(const Point pos);
    void setKinds(const int kinds);
    void setCreatedframe(const int frame);
};

#endif