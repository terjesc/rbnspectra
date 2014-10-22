#pragma once

#include "spectrumgraph.h"
#include "spectrumhistoryview.h"

#include <vector>
#include <QWidget>
#include <QtGui>

class SpectrumView : public QWidget
{
  Q_OBJECT

public:
  SpectrumView(QWidget *parent = 0);

private slots:
  void addSpectrum(const std::vector<int> &);
  void clearSpectrum();
  void addRandomSpectrum();

private:
  SpectrumGraph *graph;
  SpectrumHistoryView *history;

};

