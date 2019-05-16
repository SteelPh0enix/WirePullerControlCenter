#ifndef WIREPULLERWINDOW_HPP
#define WIREPULLERWINDOW_HPP

#include <QMainWindow>

namespace Ui {
class WirePullerWindow;
}

class WirePullerWindow : public QMainWindow {
  Q_OBJECT

 public:
  explicit WirePullerWindow(QWidget* parent = nullptr);
  ~WirePullerWindow();

 private:
  Ui::WirePullerWindow* ui;
};

#endif  // WIREPULLERWINDOW_HPP
