#ifndef WIREPULLERWINDOW_HPP
#define WIREPULLERWINDOW_HPP

#include <QMainWindow>
#include "serialportinfomanager.hpp"
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

 private:
  Ui::WirePullerWindow* ui{nullptr};
  SerialPortInfoManager serialPortInfoManager{};
  WirePuller wirePuller;

  bool movingState{false};
};

#endif  // WIREPULLERWINDOW_HPP
