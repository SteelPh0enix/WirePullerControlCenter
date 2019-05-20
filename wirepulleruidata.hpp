#ifndef WIREPULLERUIDATA_HPP
#define WIREPULLERUIDATA_HPP
#include <QHash>
#include <QString>

struct WirePullerUIData {
  enum class RequestType { None, SetMotorPower, SetPosition };
  using Data = QHash<QString, int>;

  RequestType requestType;
  Data data;
};

#endif  // WIREPULLERUIDATA_HPP
