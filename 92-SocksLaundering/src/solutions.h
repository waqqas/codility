#ifndef _SOLUTIONS_H_
#define _SOLUTIONS_H_

#include <cstdint>
#include <vector>

namespace Codility {

template <int32_t S> class SocksLaundering {
public:
  using sock_list = std::vector<int32_t>;
  using pair_count = int32_t;

  pair_count solution(int32_t max_wash_count, sock_list &clean,
                      sock_list &dirty) {
    pair_count pairs = 0;
    
    return pairs;
  }

private:
  pair_count make_sock_pairs(sock_list &list) { return 0; }
};

} // namespace Codility
#endif
