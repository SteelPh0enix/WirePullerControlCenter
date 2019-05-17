#ifndef MESSAGEPARSER_HPP
#define MESSAGEPARSER_HPP

#include <Messages/wirepullerrequest.hpp>
#include <Messages/wirepullerresponse.hpp>
#include <QByteArray>

class MessageParser {
 public:
  virtual ~MessageParser() = default;
  virtual QByteArray parseRequest(WirePullerRequest const& request) = 0;
  virtual WirePullerResponse parseResponse(QByteArray const& response) = 0;
};

#endif  // MESSAGEPARSER_HPP
