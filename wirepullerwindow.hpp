#ifndef WIREPULLERWINDOW_HPP
#define WIREPULLERWINDOW_HPP

#include <QMainWindow>
#include "serialportinfomanager.hpp"
#include "wirepuller.hpp"
#include "wirepullerdata.hpp"
#include "wirepulleruidata.hpp"

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
  void updateWirePullerData(WirePullerData const& data);

 signals:
  void wirePullerDataUpdated(WirePullerUIData const& data);

 private:
  Ui::WirePullerWindow* ui{nullptr};
  SerialPortInfoManager serialPortInfoManager{};
  WirePuller wirePuller;

  void setMovingState(bool state);
  bool movingState{false};

  WirePullerUIData readDataFromUI(WirePullerUIData::RequestType type) const;
  WirePullerUIData::Data readMotorPowersFromUI() const;
  WirePullerUIData::Data readAxisDistancesFromUI() const;

  int translateEncoderReadingsToDistance(int rawData) const;
};

#endif  // WIREPULLERWINDOW_HPP
