#include "requestbuilder.hpp"
#include <algorithm>
#include "jsonconstants.hpp"

WirePullerRequest RequestBuilder::makeSetMotorSpeedRequest(
    QHash<QString, int> const& motorList) {
  WirePullerRequest request{};

  request.type = Message::RequestType::SetMotorSpeed;
  std::copy(motorList.cbegin(), motorList.cend(),
            std::inserter(request.data, request.data.begin()));

  return request;
}

WirePullerRequest RequestBuilder::makeGetDataRequest(
    Message::DataFlags const& dataType) {
  WirePullerRequest request{};

  request.type = Message::RequestType::GetData;
  request.data.insert(JsonKey::DataRequestFlag, static_cast<int>(dataType));

  return request;
}

WirePullerRequest RequestBuilder::makeResetEncoderRequest(
    QHash<QString, bool> const& encodersList) {
  WirePullerRequest request{};

  request.type = Message::RequestType::ResetEncoder;
  std::copy(encodersList.cbegin(), encodersList.cend(),
            std::inserter(request.data, request.data.begin()));

  return request;
}
