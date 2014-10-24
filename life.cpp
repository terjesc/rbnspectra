
#include "life.h"

Life::Life()
{
  reset();
}

unsigned int Life::index(unsigned int row, unsigned int column)
{
  row = row % getHeight();
  column = column % getWidth();
  return row * getWidth() + column;
}

void Life::tick(unsigned int times)
{
  for (unsigned int i = 0; i < times; ++i)
  {
    tick();
  }
}

void Life::tick()
{
  // One cell at a time
  for (unsigned int row=0; row < getHeight(); ++row)
  {
    for (unsigned int column=0; column < getWidth(); ++column)
    {
      // Calculate indexes
      unsigned int current = index(row, column);
      unsigned int neighbours[] = {
        index(row+getHeight(), column+getWidth()), index(row+getHeight(), column), index(row+getHeight(), column+1),
        index(row,             column+getWidth()),                                 index(row,             column+1),
        index(row+1,           column+getWidth()), index(row+1,           column), index(row+1,           column+1)};

      // Count live neighbours
      int liveNeighbours = 0;
      for (int i = 0; i < 8; ++i)
      {
        liveNeighbours += cells[neighbours[i]].getState();
      }

      // Decide and stage next state
      if (cells[current].getState() == false)
      {
        if (liveNeighbours == 3)
          cells[current].stageState(true);
        else
          cells[current].stageState(false);
      }
      else if (cells[current].getState() == true)
      {
        if (liveNeighbours == 3 || liveNeighbours == 2)
          cells[current].stageState(true);
        else
          cells[current].stageState(false);
      }
    }
  }

  // Commit all
  commitStagedStates();
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

  unsigned int maxSize = width * height;

  for (std::vector<bool>::iterator cell = bitmap.begin(); cell != bitmap.end(); ++cell)
  {
    // Initialize cell
    cells.push_back(Cell(*cell));
    
    // Stop if gone too far.
    if (cells.size() >= maxSize)
      break;
  }

  // Populate cells (if missing)
  while (cells.size() < maxSize)
    cells.push_back(Cell(false));

}

void Life::commitStagedStates()
{
  for (std::vector<Cell>::iterator cell = cells.begin(); cell != cells.end(); ++cell)
  {
    cell->commitState();
  }
}

