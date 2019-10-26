#ifndef _SOLUTIONS_H_
#define _SOLUTIONS_H_

#include <algorithm>
#include <cstdint>
#include <vector>

namespace Codility {
using namespace std;

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
      sock_list::iterator second = find_second_pair(list.begin(), list.end());

      // remove pair from the list
      if (second != list.end()) {
        list.erase(second); // remove 2nd first, so first iterator is not
                            // invalidated
        list.erase(list.begin());
        count++;
      }
    }
    return count;
  }

  sock_list::iterator find_second_pair(const sock_list::iterator &start,
                                       const sock_list::iterator &end) {
    return find(start + 1, end, *start);
  }
};

} // namespace Codility
#endif
