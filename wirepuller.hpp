#ifndef WIREPULLER_HPP
#define WIREPULLER_HPP

#include <QObject>
#include <QSerialPort>
#include <QString>

class WirePuller : public QObject {
  Q_OBJECT
 public:
  WirePuller(QObject* parent = nullptr);
  ~WirePuller();

  bool setSerialPort(QString const& portName);

  bool startMoving();
  bool stopMoving();

  bool movingState() const;
  bool isPortOpen() const;

  void callibrate();

 private:
  void setMovingState(bool state);

  bool movingStateFlag{false};
  QSerialPort serialPort;
};

#endif  // WIREPULLER_HPP
