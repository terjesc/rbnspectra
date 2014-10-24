#pragma once

#include "cell.h"

class Life
{
  public:
    Life();

    void tick();
    void clear();
    void reset();
    void load(std::vector<bool> bitmap, unsigned int width, unsigned int height);

    unsigned int getWidth() { return width; }
    unsigned int getHeight() { return height; }

  private:
    void setWidth(unsigned int width) { this->width = width; }
    void setHeight(unsigned int height) { this->height = height; }
    std::vector<Cell> cells;
    unsigned int width, height;
    
    unsigned int index(unsigned int row, unsigned int column);
    void commitStagedStates();

};

