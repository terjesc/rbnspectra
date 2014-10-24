
#include "cell.h"

#include <deque>
#include <vector>

Cell::Cell()
{
  historyMaxSize = 100;
  stagedState = 0;
}

Cell::Cell(bool initialState)
{
  historyMaxSize = 100;
  stagedState = 0;
  setState(initialState);
}

void Cell::reset()
{
  stagedState = 0;
  history = std::deque<bool> ();
}


// Current state

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

bool Cell::getState(unsigned int offset)
{
  return history[offset];
}


// State staging

void Cell::stageState(bool state)
{
  stagedState = state;
}

void Cell::commitState()
{
  setState(stagedState);
}


// History

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


// Aggregate information from history

unsigned int Cell::changes(unsigned int historySize)
{
  unsigned int changeCount = 0;

  if (historySize == 0)
    historySize = history.size();

  std::deque<bool>::iterator it = history.begin();
  bool previous = *it;
  it++;

  for (unsigned int i = 1; i < historySize; ++i)
  {
    if (it == history.end())
      break;

    if (previous != *it)
    {
      previous = *it;
      ++changeCount;
    }
    
    it++;
  }

  return changeCount;
}

unsigned int Cell::liveCount(unsigned int historySize)
{
  unsigned int liveCount = 0;

  if (historySize == 0)
    historySize = history.size();

  std::deque<bool>::iterator it = history.begin();

  for (unsigned int i = 0; i < historySize; ++i)
  {
    if (it == history.end())
      break;

    if (*it)
      ++liveCount;
    
    it++;
  }

  return liveCount;
}

unsigned int Cell::deadCount(unsigned int historySize)
{
  if (historySize == 0)
    historySize = history.size();

  return historySize - liveCount(historySize);
}

