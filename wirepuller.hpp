#ifndef WIREPULLER_HPP
#define WIREPULLER_HPP

#include <QObject>
#include <QString>

class WirePuller : public QObject {
  Q_OBJECT
 public:
  WirePuller(QObject* parent = nullptr);
  ~WirePuller();

  bool setSerialPort(QString const& portName);

  void startMoving();
  void stopMoving();

  bool movingState() const;

  void callibrate();

 private:
  bool movingStateFlag{false};
};

#endif  // WIREPULLER_HPP
