#pragma once

#include <deque>
#include <vector>

class Cell
{
  public:
    Cell();
    Cell(bool initialValue);

    void reset();

    // Current state
    void setState(bool state);
    bool getState();
    bool getState(unsigned int offset);

    // State staging
    void stageState(bool state);
    void commitState();

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
    bool stagedState;
};

