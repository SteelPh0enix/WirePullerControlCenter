#include "wirepullerwindow.hpp"
#include "ui_wirepullerwindow.h"

WirePullerWindow::WirePullerWindow(QWidget* parent)
    : QMainWindow(parent), ui(new Ui::WirePullerWindow) {
  ui->setupUi(this);
}

WirePullerWindow::~WirePullerWindow() {
  delete ui;
}
