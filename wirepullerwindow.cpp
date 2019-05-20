#include "wirepullerwindow.hpp"
#include <QMessageBox>
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

void WirePullerWindow::on_openSerialPortButton_clicked() {
  auto selectedPort = ui->serialPortsListCombo->currentText();
  if (wirePuller.setSerialPort(selectedPort)) {
    ui->openedPortName->setText(QString("Opened port: %1").arg(selectedPort));
  } else {
    ui->openedPortName->setText("Unable to open port!");
  }
}

void WirePullerWindow::on_helpButton_clicked() {
  QMessageBox::question(
      this, "Help",
      "* Use sliders to set motors speed.\n"
      "* Enter motor offset from calibrated "
      "position in input below sliders and press <Enter> to move them to "
      "specified position.\n"
      "* To callibrate, first press <Callibrate> button, "
      "wait until elements will hit endstops and stop moving, and then slowly "
      "move them using sliders by 1cm and write tick count to the input "
      "corresponding to motor.\n"
      "While uncallibrated, <Distance from origin> label will show raw tick "
      "count instead of position, which you can use to callibrate readings.",
      QMessageBox::Ok);
}

void WirePullerWindow::on_actionExit_triggered() {
  QApplication::exit();
}

void WirePullerWindow::on_actionButton_clicked() {
  if (movingState) {
    setMovingState(!wirePuller.stopMoving());
  } else {
    setMovingState(wirePuller.startMoving());
  }
}

void WirePullerWindow::on_resetButton_clicked() {
  wirePuller.callibrate();
}

void WirePullerWindow::setMovingState(bool state) {
  if (state) {
    ui->actionButton->setText("Stop");
  } else {
    ui->actionButton->setText("Start");
  }

  movingState = state;
}
