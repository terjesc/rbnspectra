#pragma once

#include <deque>
#include <vector>

class Cell
{
  public:
    Cell();

    // Current state
    void setState(bool state);
    bool getState();
    bool getState(unsigned int offset);

    // History
    unsigned int getHistorySize();
    std::vector<bool> getHistory();

    // Aggregate information from history
    unsigned int changes(unsigned int historySize = 0);
    unsigned int liveCount(unsigned int historySize = 0);
    unsigned int deadCount(unsigned int historySize = 0);

  private:
    unsigned int historyMaxSize;
    std::deque<bool> history;
};

