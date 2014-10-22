#pragma once

#include <deque>
#include <vector>

class Cell
{
  public:
    Cell();

    void setState(bool state);
    bool getState();
    bool getState(int offset);

    unsigned int getHistorySize();
    std::vector<bool> getHistory();

  private:
    unsigned int historyMaxSize;
    std::deque<bool> history;
};

