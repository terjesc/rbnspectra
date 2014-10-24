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
  window.show();

  Life life;
  std::vector<bool> initialLife;
  initialLife.push_back(false);
  initialLife.push_back(true);
  initialLife.push_back(true);
  initialLife.push_back(true);
  life.load(initialLife, 8, 8);
  life.tick(10);


  return app.exec();
}

