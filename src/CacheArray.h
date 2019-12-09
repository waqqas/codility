#ifndef CACHE_ARRAY_H
#define CACHE_ARRAY_H

#include <array>
#include <cstddef>

namespace Cache {

template <typename T, size_t SIZE>
class Array {

  private:
    using array_type = std::array<T, SIZE>;
    using size_type = typename array_type::size_type;
    using reference = typename array_type::reference;
    using const_reference = typename array_type::const_reference;

    using offset_type = std::array<size_type, SIZE>;

    class Proxy {
        Array& object;
        size_type logical;

      public:
        Proxy(Array& object, size_type logical)
        : object(object)
        , logical(logical)
        {
        }
        operator T() const { return object.read(logical); }
        void operator=(T const& value) { object.write(logical, value); }
    };

    array_type data;
    offset_type offsets;

  public:
    Array()
    : offsets{1U, 0U, 2U}
    {
    }

    inline const_reference read(size_type logical) const { return data[logical]; }
    inline void write(size_type logical, T const& value)
    {
        size_type physical = offsets[logical];
        data[physical] = value;
    }

    Proxy operator[](size_type logical) { return Proxy(*this, logical); }

    reference operator[](size_type logical) const { return read(logical); }
};
} // namespace Cache
#endif
