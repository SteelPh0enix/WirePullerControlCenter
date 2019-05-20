#include "wirepuller.hpp"

WirePuller::WirePuller(QObject* parent) : QObject(parent) {
  communicator.setBaudRate(QSerialPort::Baud115200);
  communicator.setDataParser(&jsonMessageParser);
}

bool WirePuller::setSerialPort(const QString& portName) {
  communicator.setSerialPort(portName);
  return communicator.open();
}

bool WirePuller::startMoving() {
  if (!isPortOpen()) {
    return false;
  }

  return true;
}

bool WirePuller::stopMoving() {
  if (!isPortOpen()) {
    return false;
  }

  return true;
}

void WirePuller::callibrate() {}

bool WirePuller::movingState() const {
  return movingStateFlag;
}

bool WirePuller::isPortOpen() const {
  return communicator.isOpen();
}

void WirePuller::setMovingState(bool state) {
  movingStateFlag = state;
}
