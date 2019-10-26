#ifndef _STR_SYMMETRY_POINT_H_
#define _STR_SYMMETRY_POINT_H_

#include <cstdint>
#include <string>

namespace Codility {
bool is_even(std::size_t size) { return size % 2 == 0; }

template <int32_t S> class StrSymmetryPoint {
  using string = std::string;

public:
  int32_t solution(string &input) {
    if (input.length() < 1 || is_even(input.length())) {
      return -1;
    }

    string::iterator fwd = input.begin();
    string::iterator back = input.begin() + input.length() - 1;

    // find the first non-matching character
    size_t index = 0;
    for (; fwd != back; ++fwd, --back, ++index) {
      if (*fwd != *back) {
        break;
      }
    }

    return (input.length() / 2) == index ? index : -1;
  }
};

} // namespace Codility
#endif
