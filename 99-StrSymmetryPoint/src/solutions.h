#ifndef _SOLUTIONS_H_
#define _SOLUTIONS_H_

#include <cstdint>
#include <string>

namespace Codility {
template <int32_t S = 1> class StrSymmetryPoint {
public:
  int32_t solution(const std::string &input) { return -1; }
};

template <> class StrSymmetryPoint<2> {
public:
  int32_t solution(const std::string &input) { return -1; }
};
} // namespace Codility
#endif