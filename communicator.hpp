#ifndef COMMUNICATOR_HPP
#define COMMUNICATOR_HPP

#include <Messages/messageparser.hpp>
#include <Messages/wirepullerrequest.hpp>
#include <Messages/wirepullerresponse.hpp>
#include <QSerialPort>

class Communicator {
 public:
  void setSerialPort(QSerialPort port);
  void setDataParser(MessageParser* parser);

  WirePullerResponse send(WirePullerRequest const& request);

  bool open();
  void close();
  void setBaudRate(QSerialPort::BaudRate baudRate);

 private:
  MessageParser* messageParser{nullptr};
  QSerialPort serialPort;
};

#endif  // COMMUNICATOR_HPP
