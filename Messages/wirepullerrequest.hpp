#ifndef WIREPULLERREQUEST_HPP
#define WIREPULLERREQUEST_HPP

#include <QHash>
#include <QString>
#include <QVariant>
#include "messagetypes.hpp"

struct WirePullerRequest {
  Message::RequestType type;
  QHash<QString, QVariant> data;
};

#endif  // WIREPULLERREQUEST_HPP
