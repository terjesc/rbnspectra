
#include "cell.h"

#include <deque>
#include <vector>

Cell::Cell()
{
  historyMaxSize = 100;
}

void Cell::setState(bool state)
{
  history.push_front(state);

  while (history.size() > historyMaxSize)
  {
    history.pop_back();
  }
}

bool Cell::getState()
{
  return history.back();
}

bool Cell::getState(int offset)
{
  return history[offset];
}

unsigned int Cell::getHistorySize()
{
  return history.size();
}

std::vector<bool> Cell::getHistory()
{
  std::vector<bool> result;

  for (std::deque<bool>::iterator it = history.begin(); it != history.end(); ++it)
  {
    result.push_back(*it);
  }

  return result;
}

