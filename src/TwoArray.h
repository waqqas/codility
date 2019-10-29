#ifndef _TWO_ARRAY_H_
#define _TWO_ARRAY_H_

#include <cstddef>
#include <vector>

namespace Codility {
using namespace std;
template <int32_t S>
class TwoArray {
  public:
    using value_type = int32_t;
    value_type solution(const vector<value_type>& input, size_t offset) { return input[offset]; }
};
} // namespace Codility

#endif
