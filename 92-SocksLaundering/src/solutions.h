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
    pair_count pairs = make_clean_pairs(clean);
    pairs += make_clean_and_dirty_pairs(clean, dirty, max_wash_count);
    pairs += make_dirty_pairs(dirty, max_wash_count);
    return pairs;
  }

private:
  pair_count make_dirty_pairs(sock_list &list, int32_t &max_wash_count) {
    pair_count count = 0;

    auto first = list.begin();
    while (first != list.end()) {
      const auto second = find_second_pair(first, list.end());

      // remove pair from the list
      if (second != list.end()) {
        // check if two socks can be washed
        if (max_wash_count >= 2) {
          list.erase(second); // remove 2nd first, so first iterator is not
                              // invalidated
          first = list.erase(first);
          count++;
          max_wash_count -= 2;
        } else {
          break;
        }
      } else {
        ++first;
      }
    }
    return count;
  }

  pair_count make_clean_and_dirty_pairs(sock_list &clean, sock_list &dirty,
                                        int32_t &max_wash_count) {
    pair_count count = 0;
    auto clean_sock = clean.begin();
    while (clean_sock != clean.end()) {
      const auto dirty_sock = find(begin(dirty), end(dirty), *clean_sock);
      if (dirty_sock != std::end(dirty)) {
        if (max_wash_count > 0) {
          count++;
          max_wash_count--;
          dirty.erase(dirty_sock);
          clean_sock = clean.erase(clean_sock);

        } else {
          break;
        }
      } else {
        ++clean_sock;
      }
    }
    return count;
  }

  pair_count make_clean_pairs(sock_list &list) {
    pair_count count = 0;

    auto first = list.begin();
    while (first != list.end()) {
      const auto second = find_second_pair(first, list.end());

      // remove pair from the list
      if (second != list.end()) {
        list.erase(second); // remove 2nd first, so first iterator is not
                            // invalidated
        first = list.erase(first);
        count++;
      } else {
        ++first;
      }
    }
    return count;
  }

  inline sock_list::iterator find_second_pair(const sock_list::iterator &start,
                                              const sock_list::iterator &end) {
    return find(start + 1, end, *start);
  }
};

} // namespace Codility
#endif
