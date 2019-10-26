#ifndef _SOLUTIONS_H_
#define _SOLUTIONS_H_

#include <algorithm>
#include <cstdint>
#include <vector>

namespace Codility {

template <int32_t S> class SocksLaundering {
public:
  using color = int32_t;
  using sock_list = std::vector<color>;
  using pair_count = int32_t;

  pair_count solution(int32_t max_wash_count, sock_list &clean,
                      sock_list &dirty) {
    pair_count pairs = 0;

    // make pairs in clean list
    pairs = make_sock_pairs(clean);

    return pairs;
  }

private:
  pair_count make_sock_pairs(sock_list &list) {
    pair_count count = 0;

    while (!list.empty()) {
      count += make_pair(list);
    }
    return count;
  }

  pair_count make_pair(sock_list &list) {
    sock_list::iterator first_pair = list.begin();
    // find in second pair
    sock_list::iterator second_pair =
        std::find(first_pair + 1, std::end(list), *first_pair);
    if (second_pair != list.end()) {
      list.erase(second_pair);    // remove 2nd first, so first iterator is not invalidated
      list.erase(first_pair);
      return 1;
    }
    return 0;
  }
};

} // namespace Codility
#endif
