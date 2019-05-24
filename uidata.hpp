#ifndef UIDATA_HPP
#define UIDATA_HPP

namespace UIData {
enum class Axis { None, X, Wheel, Breaker };
struct AxisInputData {
  bool leftEndstopState;
  bool rightEndstopState;
  int distanceTicks;
};

struct AxisOutputData {
  enum class RequestType { None, SetPower, SetPosition };
  int power;
  int distance;
};
}  // namespace UIData

#endif  // UIDATA_HPP
