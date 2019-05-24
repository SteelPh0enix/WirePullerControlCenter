#ifndef UIDATA_HPP
#define UIDATA_HPP

namespace UIData {
enum class Axis { None, X, Wheel, Breaker };
struct AxisData {
  bool leftEndstopState;
  bool rightEndstopState;
  int distanceTicks;
};
}  // namespace UIData

#endif  // UIDATA_HPP
