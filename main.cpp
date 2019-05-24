#include <QApplication>
#include <QObject>
#include "wirepuller.hpp"
#include "wirepullerwindow.hpp"

int main(int argc, char* argv[]) {
  QApplication a(argc, argv);
  WirePullerWindow ui;
  WirePuller wirePuller;

  QObject::connect(&ui, &WirePullerWindow::openSerialPort, &wirePuller,
                   &WirePuller::openSerialPort);
  QObject::connect(&wirePuller, &WirePuller::serialPortOpened, &ui,
                   &WirePullerWindow::serialPortOpenFeedback);

  ui.show();
  return a.exec();
}
