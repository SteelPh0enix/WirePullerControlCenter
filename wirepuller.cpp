#include "wirepuller.hpp"

WirePuller::WirePuller(QObject* parent) : QObject(parent) {
  serialPort.setBaudRate(QSerialPort::Baud115200);
}

WirePuller::~WirePuller() {
  serialPort.close();
}

bool WirePuller::setSerialPort(const QString& portName) {
  serialPort.close();
  serialPort.setPortName(portName);
  return serialPort.open(QIODevice::ReadWrite);
}

bool WirePuller::startMoving() {
  return true;
}

bool WirePuller::stopMoving() {
  return true;
}

void WirePuller::callibrate() {}

bool WirePuller::movingState() const {
  return movingStateFlag;
}

bool WirePuller::isPortOpen() const {
  return serialPort.isOpen();
}

void WirePuller::setMovingState(bool state) {
  movingStateFlag = state;
}
