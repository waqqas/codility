#ifndef CACHE_ARRAY_H
#define CACHE_ARRAY_H

#include <array>
#include <cstddef>
#include <iostream>

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

    void generate_offset(offset_type& base, size_type size, size_type& offset)
    {
        size_t mid = size / 2;
        offsets[mid / 2] = offset++;
        offsets[(size - mid) / 2 + mid] = offset++;
    }

  public:
    Array()
    {
        size_type offset = 0;
        size_type size = offsets.size();

        size_t mid = size / 2;
        offsets[mid] = offset++;
        generate_offset(offsets, size, offset);

        if (offsets.size() == 4) {
            offsets[0] = offset;
        } else if (offsets.size() == 5) {
            offsets[0] = offset++;
            offsets[4] = offset;
        } else if (offsets.size() == 6) {
            generate_offset(offsets, 3, offset);
            offsets[5] = offset;
        }

        for (const auto& value : offsets) {
            std::cout << value << ",";
        }
        std::cout << std::endl;
    }

    inline const_reference read(size_type logical) const
    {
        // std::cout << "read:  [" << logical << "] = " << data[logical] << std::endl;
        return data[logical];
    }

    inline void write(size_type logical, T const& value)
    {
        size_type physical = offsets[logical];
        data[physical] = value;
        // std::cout << "write: " << logical << " > [" << physical << "]= " << data[physical] << std::endl;
    }

    Proxy operator[](size_type logical) { return Proxy(*this, logical); }

    reference operator[](size_type logical) const { return read(logical); }
};
} // namespace Cache
#endif
