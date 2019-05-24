#ifndef WIREPULLER_HPP
#define WIREPULLER_HPP

#include <QObject>
#include <QSerialPort>
#include <QString>
#include <QTimer>
#include "Messages/jsonmessageparser.hpp"
#include "communicator.hpp"
#include "requestbuilder.hpp"
#include "uidata.hpp"

class WirePuller : public QObject {
  Q_OBJECT
 public:
  WirePuller(QObject* parent = nullptr);

  bool setSerialPort(QString const& portName);

  bool movingState() const;
  bool isPortOpen() const;

 signals:
  void serialPortOpened(bool flag);
  void movingStateFeedback(bool state);
  void updateUI(UIData::Axis axis, UIData::AxisData const& data);

 public slots:
  void openSerialPort(QString const& portName);
  void startMoving();
  void stopMoving();
  void callibrate();

 private:
  void setMovingState(bool state);
  bool movingStateFlag{false};

  RequestBuilder requestBuilder;
  Communicator communicator;
  JsonMessageParser jsonMessageParser;

  QTimer serialSenderTimer;
};

#endif  // WIREPULLER_HPP
