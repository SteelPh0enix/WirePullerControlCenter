#ifndef WIREPULLERRESPONSE_HPP
#define WIREPULLERRESPONSE_HPP

#include <QHash>
#include <QString>
#include <QVariant>
#include "messagetypes.hpp"

struct WirePullerResponse {
  Message::ResponseType type;
  QHash<QString, QVariant> data;
};

#endif  // WIREPULLERRESPONSE_HPP
