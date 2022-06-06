#ifndef _RENDERABLE_
#define _RENDERABLE_

#include <ncurses.h>

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