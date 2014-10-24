#include <QApplication>
// #include "mainwindow.h"
#include "spectrumview.h"
#include "spectrumgraph.h"
#include "spectrumhistoryview.h"
#include "life.h"
#include <cstdlib>
#include <ctime>

int main(int argc, char **argv)
{
//  Q_INIT_RESOURCE(application);

  std::srand(std::time(0));

  QApplication app(argc, argv);
  
  app.setApplicationName("RBN-spectra");
  SpectrumView window;

  /*
  std::vector<std::vector<int> > history;
  int lineCount = std::rand() % 128;
  int valueCount = std::rand() % 256;
  lineCount = 256;
  valueCount = 128;
  for (int i=0; i < lineCount; ++i)
  {
    std::vector<int> values;
    for (int i=0; i < valueCount; ++i)
    {
      values.push_back(std::rand() % 256);
    }
    history.push_back(values);
  }
  window.setHistory(history);
  */

  window.show();
  return app.exec();
}

