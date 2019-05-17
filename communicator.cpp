#include "communicator.hpp"

WirePullerResponse Communicator::send(WirePullerRequest const& request) {
  QByteArray rawRequest = messageParser->parseRequest(request);
  serialPort.write(rawRequest);

  QByteArray rawResponse = serialPort.readLine();
  return messageParser->parseResponse(rawResponse);
}

bool Communicator::open() {
  return serialPort.open(QIODevice::ReadWrite | QIODevice::Text);
}

void Communicator::close() {
  serialPort.close();
}

void Communicator::setBaudRate(QSerialPort::BaudRate baudRate) {
  bool wasOpen{false};
  if (serialPort.isOpen()) {
    close();
    wasOpen = true;
  }

  serialPort.setBaudRate(baudRate);
  if (wasOpen) {
    open();
  }
}
