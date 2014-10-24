
#include "life.h"

void Life::tick()
{

}

void Life::clear()
{
  for (std::vector<Cell>::iterator cell = cells.begin(); cell != cells.end(); ++cell)
  {
    cell->reset();
  }
}

void Life::reset()
{
  cells.clear();
  setWidth(0);
  setHeight(0);
}

void Life::load(std::vector<bool> bitmap, unsigned int width, unsigned int height)
{
  reset();

  setWidth(width);
  setHeight(height);

  for (std::vector<bool>::iterator cell = bitmap.begin(); cell != bitmap.end(); ++cell)
  {
    cells.push_back(Cell(*cell));
  }

}

