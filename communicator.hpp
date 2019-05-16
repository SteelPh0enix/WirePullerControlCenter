#ifndef COMMUNICATOR_HPP
#define COMMUNICATOR_HPP

#include <QObject>
#include <QSerialPort>
#include <messageparser.hpp>
#include <wirepullerrequest.hpp>
#include <wirepullerresponse.hpp>

class Communicator : public QObject {
  Q_OBJECT
 public:
  explicit Communicator(QObject* parent = nullptr);

  void setSerialPort(QSerialPort port);
  void setDataParser(MessageParser* parser);

  WirePullerResponse send(WirePullerRequest const& data) const;

 signals:

 public slots:

 private:
  MessageParser* messageParser{nullptr};
};

#endif  // COMMUNICATOR_HPP
