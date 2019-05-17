#ifndef REQUESTBUILDER_HPP
#define REQUESTBUILDER_HPP

#include <QHash>
#include <QString>
#include "Messages/wirepullerrequest.hpp"
#include "devicenames.hpp"

class RequestBuilder {
 public:
  static WirePullerRequest makeSetMotorSpeedRequest(
      QHash<QString, int> const& motorList);

  static WirePullerRequest makeGetDataRequest(
      Message::DataFlags const& dataType);

  static WirePullerRequest makeResetEncoderRequest(
      QHash<QString, bool> const& encodersList);
};

#endif  // REQUESTBUILDER_HPP
