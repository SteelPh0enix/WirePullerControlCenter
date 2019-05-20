#ifndef WIREPULLERDATA_HPP
#define WIREPULLERDATA_HPP
#include <QHash>
#include <QString>

struct WirePullerData {
  using MotorPowers = QHash<QString, int>;
  using EndstopStates = QHash<QString, bool>;
  using EncodersData = QHash<QString, int>;

  MotorPowers motorPowers;
  EndstopStates endstopStates;
  EncodersData encodersData;
};

#endif  // WIREPULLERDATA_HPP
