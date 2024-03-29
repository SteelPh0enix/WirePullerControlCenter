#include "wirepuller.hpp"

WirePuller::WirePuller(QObject* parent) : QObject(parent) {
  communicator.setBaudRate(QSerialPort::Baud115200);
  communicator.setDataParser(&jsonMessageParser);

  communicatorTimer.setInterval(100);
  QObject::connect(&communicatorTimer, &QTimer::timeout, this,
                   &WirePuller::sendData);
}

bool WirePuller::setSerialPort(const QString& portName) {
  communicator.setSerialPort(portName);
  return communicator.open();
}

void WirePuller::startMoving() {
  if (!isPortOpen() || movingState()) {
    return;
  }

  communicatorTimer.start();

  setMovingState(true);
}

void WirePuller::stopMoving() {
  if (!isPortOpen() || !movingState()) {
    return;
  }

  communicatorTimer.stop();

  setMovingState(false);
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
  emit movingStateFeedback(state);
}

void WirePuller::openSerialPort(QString const& portName) {
  emit serialPortOpened(setSerialPort(portName));
}

void WirePuller::axisUpdated(UIData::Axis axis,
                             UIData::AxisOutputData const& data) {
  storedData[axis] = data;
}

void WirePuller::sendData() const {}
