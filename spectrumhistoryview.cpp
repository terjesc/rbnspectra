#include "spectrumhistoryview.h"
#include <QWidget>
#include <QPainter>
#include <deque>

SpectrumHistoryView::SpectrumHistoryView(QWidget *parent)
  : QWidget(parent)
{
  history = std::deque<std::vector<int> >();
  maxAmplitude=255;
  
  historyMaxSize=255;
  
  setMinimumSize(256, 256);

}

void SpectrumHistoryView::addSpectrum(const std::vector<int> &newSpectrum)
{
  history.push_front(newSpectrum);

  while (history.size() > historyMaxSize)
  {
    history.pop_back();
  }
}

void SpectrumHistoryView::setHistory(const std::deque<std::vector<int> > &newHistory)
{
  history = newHistory;
}

void SpectrumHistoryView::clearHistory()
{
  history = std::deque<std::vector<int> >();
}

int SpectrumHistoryView::getHistorySize()
{
  return history.size();
}

void SpectrumHistoryView::paintEvent(QPaintEvent *)
{
  QColor barColor(255, 0, 0);

  QPainter painter(this);
  painter.setBrush(QColor(0, 255, 0));

  for (int line=0; line < getHistorySize(); ++line)
  {
    for (unsigned int column=0; column < history[line].size(); ++column)
    {
      painter.setBrush(QColor(history[line][column]));
      painter.setPen(QColor(history[line][column]));
      painter.drawLine
        (
          column * width() / history[line].size(),//x1
          line,//y1
          (column + 1) * width() / history[line].size(),//x2
          line//y2
        );
    }
  }
}

