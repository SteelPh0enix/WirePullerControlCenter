#ifndef WIREPULLERWINDOW_HPP
#define WIREPULLERWINDOW_HPP

#include <QMainWindow>
#include "serialportinfomanager.hpp"
#include "uidata.hpp"
#include "wirepuller.hpp"

namespace Ui {
class WirePullerWindow;
}

class WirePullerWindow : public QMainWindow {
  Q_OBJECT

 public:
  explicit WirePullerWindow(QWidget* parent = nullptr);
  ~WirePullerWindow();

 private slots:
  void on_refreshSerialPortsButton_clicked();
  void on_openSerialPortButton_clicked();
  void on_helpButton_clicked();
  void on_actionExit_triggered();
  void on_actionButton_clicked();
  void on_resetButton_clicked();

 public slots:
  void setMovingState(bool state);
  void updateAxisData(UIData::Axis axis, UIData::AxisData const& data);
  void serialPortOpenFeedback(bool isOpen);

 signals:
  void callibrate();
  void startMoving();
  void stopMoving();
  void openSerialPort(QString const& portName);

 private:
  Ui::WirePullerWindow* ui{nullptr};
  SerialPortInfoManager serialPortInfoManager{};

  bool movingState{false};
  bool portOpenState{false};

  double translateTicksToDistance(UIData::Axis axis, double ticks) const;
};

#endif  // WIREPULLERWINDOW_HPP
