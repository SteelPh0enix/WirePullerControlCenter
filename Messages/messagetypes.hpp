#ifndef MESSAGETYPES_HPP
#define MESSAGETYPES_HPP

namespace Message {
enum class RequestType { None, SetMotorSpeed, GetData, ResetEncoder };

enum class ResponseType { None, Error, Data };

enum class DataFlags { Motor = 1, Endstop = 2, Encoder = 4 };
}  // namespace Message

#endif  // MESSAGETYPES_HPP
