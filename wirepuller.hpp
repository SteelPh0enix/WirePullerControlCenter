#ifndef WIREPULLER_HPP
#define WIREPULLER_HPP

#include <QObject>
#include <QSerialPort>
#include <QString>
#include "Messages/jsonmessageparser.hpp"
#include "communicator.hpp"
#include "requestbuilder.hpp"
#include "wirepullerdata.hpp"
#include "wirepulleruidata.hpp"

class WirePuller : public QObject {
  Q_OBJECT
 public:
  WirePuller(QObject* parent = nullptr);

  bool setSerialPort(QString const& portName);

  bool startMoving();
  bool stopMoving();

  bool movingState() const;
  bool isPortOpen() const;

  void callibrate();

 signals:
  void dataReceived(WirePullerData const& data);

 public slots:
  void updateData(WirePullerUIData const& data);

 private:
  void setMovingState(bool state);
  bool movingStateFlag{false};

  RequestBuilder requestBuilder;
  Communicator communicator;
  JsonMessageParser jsonMessageParser;
};

#endif  // WIREPULLER_HPP
