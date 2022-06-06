#include "Renderable.h"

void Renderable::EraseWindow(WINDOW* window)
{
  keypad(window, FALSE);
  werase(window);
  wrefresh(window);
  delwin(window);
}

void Renderable::render()
{

}

Renderable::~Renderable()
{
    EraseWindow(window);
}
