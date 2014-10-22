#include "spectrumgraph.h"
#include <QWidget>
#include <QPainter>

SpectrumGraph::SpectrumGraph(QWidget *parent)
  : QWidget(parent)
{
  spectrum = std::vector<int> (1, 0);
  maxAmplitude=255;
  
  setMinimumSize(256, 64);
}

int SpectrumGraph::getSize()
{
  return spectrum.size();
}


void SpectrumGraph::setSpectrum(const std::vector<int> &newSpectrum)
{
  spectrum = newSpectrum;
}

void SpectrumGraph::clearSpectrum()
{
  spectrum = std::vector<int> (getSize(), 0);
}


void SpectrumGraph::paintEvent(QPaintEvent *)
{
  QColor barColor(255, 0, 0);

  QPainter painter(this);
  painter.setBrush(barColor);

  for (int i = 0; i < getSize(); ++i)
  {
    painter.setBrush(QColor(spectrum[i]));
    painter.drawRect
      (
        i * width() / getSize(),
        height() - (spectrum[i] * height() / maxAmplitude),
        width() / getSize(),
        spectrum[i] * height() / maxAmplitude
      );
  }
}


