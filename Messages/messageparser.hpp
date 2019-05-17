#ifndef MESSAGEPARSER_HPP
#define MESSAGEPARSER_HPP

#include <QByteArray>
#include "wirepullerrequest.hpp"
#include "wirepullerresponse.hpp"

class MessageParser {
 public:
  virtual ~MessageParser() = default;
  virtual QByteArray parseRequest(WirePullerRequest const& request) = 0;
  virtual WirePullerResponse parseResponse(QByteArray const& response) = 0;
};

#endif  // MESSAGEPARSER_HPP
