#ifndef WIREPULLERWINDOW_HPP
#define WIREPULLERWINDOW_HPP

#include <QMainWindow>
#include <serialportinfomanager.hpp>

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

 private:
  Ui::WirePullerWindow* ui;
  SerialPortInfoManager serialPortInfoManager;
};

#endif  // WIREPULLERWINDOW_HPP
