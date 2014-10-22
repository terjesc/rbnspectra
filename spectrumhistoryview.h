#pragma once

#include <QWidget>

class SpectrumHistoryView : public QWidget
{
  Q_OBJECT

public:
  SpectrumHistoryView(QWidget *parent = 0);
  void addSpectrum(const std::vector<int> &);
  void setHistory(const std::vector<std::vector<int> > &);
  int getHistorySize();

private slots:
  void clearHistory();

private:
  std::vector<std::vector<int> > history;
  int maxAmplitude;

protected:
  void paintEvent(QPaintEvent *event);
};

