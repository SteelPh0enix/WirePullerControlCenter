#include <QApplication>
#include "wirepullerwindow.hpp"

int main(int argc, char* argv[]) {
  QApplication a(argc, argv);
  WirePullerWindow w;
  w.show();

  return a.exec();
}
