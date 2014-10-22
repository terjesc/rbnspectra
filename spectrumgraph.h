#pragma once

#include <QWidget>

class SpectrumGraph : public QWidget
{
  Q_OBJECT

public:
  SpectrumGraph(QWidget *parent = 0);
  int getSize();
  void setSpectrum(const std::vector<int> &);

private slots:
  void clearSpectrum();

private:
  std::vector<int> spectrum;
  int maxAmplitude;

protected:
  void paintEvent(QPaintEvent *event);
};

