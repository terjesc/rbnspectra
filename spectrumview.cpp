
#include "spectrumview.h"
#include <cstdlib>

#include <QtGui>
#include <QVBoxLayout>

SpectrumView::SpectrumView(QWidget *parent)
  : QWidget(parent)
{
  graph = new SpectrumGraph;
  history = new SpectrumHistoryView;

  QVBoxLayout *layout = new QVBoxLayout;
  layout->addWidget(graph);
  layout->addWidget(history);
  layout->setSpacing(0);
  setLayout(layout);

  QTimer *timer = new QTimer(this);
  connect(timer, SIGNAL(timeout()), this, SLOT(addRandomSpectrum()));
  timer->start(100);
}

void SpectrumView::addSpectrum(const std::vector<int> &newSpectrum)
{
  graph->setSpectrum(newSpectrum);
  history->addSpectrum(newSpectrum);
  
  graph->update();
  history->update();
}

void SpectrumView::addRandomSpectrum()
{
  std::vector<int> values;
  for (int i=0; i < 128; ++i)
  {
    values.push_back(std::rand() % 256);
  }
  addSpectrum(values);
}

void SpectrumView::clearSpectrum()
{
}

