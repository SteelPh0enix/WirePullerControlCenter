#include "wirepullerwindow.hpp"
#include "ui_wirepullerwindow.h"

WirePullerWindow::WirePullerWindow(QWidget* parent)
    : QMainWindow(parent), ui(new Ui::WirePullerWindow) {
  ui->setupUi(this);

  on_refreshSerialPortsButton_clicked();
}

WirePullerWindow::~WirePullerWindow() {
  delete ui;
}

void WirePullerWindow::on_refreshSerialPortsButton_clicked() {
  serialPortInfoManager.refreshPortList();
  auto portNames = serialPortInfoManager.getPortNames();
  ui->serialPortsListCombo->clear();
  for (auto const& portName : portNames) {
    ui->serialPortsListCombo->addItem(portName);
  }
}
