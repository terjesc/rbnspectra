#pragma once

#include <QWidget>
#include <deque>

class SpectrumHistoryView : public QWidget
{
  Q_OBJECT

public:
  SpectrumHistoryView(QWidget *parent = 0);
  void addSpectrum(const std::vector<int> &);
  void setHistory(const std::deque<std::vector<int> > &);
  int getHistorySize();

private slots:
  void clearHistory();

private:
  std::deque<std::vector<int> > history;
  unsigned int historyMaxSize;
  
  int maxAmplitude;

protected:
  void paintEvent(QPaintEvent *event);
};

