#include "wirepullerwindow.hpp"
#include <QMessageBox>
#include "devicenames.hpp"
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
  emit openSerialPort(selectedPort);
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
    emit stopMoving();
  } else {
    emit startMoving();
  }
}

void WirePullerWindow::on_resetButton_clicked() {
  emit stopMoving();

  if (!movingState) {
    emit callibrate();
  }
}

void WirePullerWindow::setMovingState(bool state) {
  if (state) {
    ui->actionButton->setText("Stop");
  } else {
    ui->actionButton->setText("Start");
  }

  movingState = state;
}

void WirePullerWindow::updateAxisData(WirePullerWindow::Axis axis,
                                      WirePullerWindow::AxisData const& data) {
  switch (axis) {
    case Axis::None: {
      break;
    }
    case Axis::X: {
      ui->xAxisLeftEndstopStatus->setChecked(data.leftEndstopState);
      ui->xAxisRightEndstopStatus->setChecked(data.rightEndstopState);
      ui->xAxisDistance->setText(QString::number(
          translateTicksToDistance(Axis::X, data.distanceTicks)));
      break;
    }
    case Axis::Wheel: {
      ui->wheelAxisLeftEndstopStatus->setChecked(data.leftEndstopState);
      ui->wheelAxisRightEndstopStatus->setChecked(data.rightEndstopState);
      ui->wheelAxisDistance->setText(QString::number(
          translateTicksToDistance(Axis::Wheel, data.distanceTicks)));
      break;
    }
    case Axis::Breaker: {
      ui->breakerAxisLeftEndstopStatus->setChecked(data.leftEndstopState);
      ui->breakerAxisRightEndstopStatus->setChecked(data.rightEndstopState);
      ui->breakerAxisDistance->setText(QString::number(
          translateTicksToDistance(Axis::Breaker, data.distanceTicks)));
      break;
    }
  }
}

void WirePullerWindow::serialPortOpenFeedback(bool isOpen) {
  if (isOpen) {
    ui->openedPortName->setText(
        QString("Opened port: %1")
            .arg(ui->serialPortsListCombo->currentText()));
    portOpenState = true;
  } else {
    ui->openedPortName->setText("Unable to open port!");
    portOpenState = false;
  }
}

double WirePullerWindow::translateTicksToDistance(Axis axis,
                                                  double ticks) const {
  double ticksPerCm{0.};
  switch (axis) {
    case Axis::None: {
      break;
    }
    case Axis::X: {
      ticksPerCm = ui->xAxisTicksPerCm->text().toDouble();
      break;
    }
    case Axis::Wheel: {
      ticksPerCm = ui->wheelAxisTicksPerCm->text().toDouble();
      break;
    }
    case Axis::Breaker: {
      ticksPerCm = ui->breakerAxisTicksPerCm->text().toDouble();
      break;
    }
  }

  if (ticksPerCm == 0) {
    return ticks;
  } else {
    return ticks / ticksPerCm;
  }
}
