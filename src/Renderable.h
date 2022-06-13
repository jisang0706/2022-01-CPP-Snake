#include <ncurses.h>

#ifndef _RENDERABLE_
#define _RENDERABLE_

class Renderable
{
public:
    virtual void render();
    ~Renderable();

protected :
    WINDOW* window;

private : 
    void EraseWindow(WINDOW* window);
	
};

#endif