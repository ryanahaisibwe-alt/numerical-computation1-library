// array_stub.hpp
// MINIMAL PLACEHOLDER for the core Array<T> class (owned by Kirungi).
// It exists only so creation_utils.hpp and its tests compile on their own.
// When the real Array is ready, delete this file and make sure the real class
// provides the same members used below:
//   Array(std::vector<size_t> shape, T fill = T())
//   const std::vector<size_t>& shape() const
//   size_t ndim() const, size_t size() const
//   T* data(), const T* data() const      (contiguous, row-major)
//   T& operator[](size_t flat_index)
//   bool operator==(const Array&) const
#pragma once

#include <cstddef>
#include <stdexcept>
#include <utility>
#include <vector>

template <class T>
class Array {
public:
    Array() = default;

    explicit Array(std::vector<std::size_t> shape, T fill = T())
        : shape_(std::move(shape)) {
        std::size_t n = 1;
        for (std::size_t d : shape_) n *= d;
        data_.assign(n, fill);
    }

    // Convenience for tests/examples: build from shape + row-major values.
    static Array from_values(std::vector<std::size_t> shape,
                             const std::vector<T>& values) {
        Array a(std::move(shape));
        if (a.size() != values.size())
            throw std::invalid_argument("from_values: size does not match shape");
        a.data_ = values;
        return a;
    }

    const std::vector<std::size_t>& shape() const { return shape_; }
    std::size_t ndim() const { return shape_.size(); }
    std::size_t size() const { return data_.size(); }

    T* data() { return data_.data(); }
    const T* data() const { return data_.data(); }

    T& operator[](std::size_t i) { return data_[i]; }
    const T& operator[](std::size_t i) const { return data_[i]; }

    bool operator==(const Array& o) const {
        return shape_ == o.shape_ && data_ == o.data_;
    }
    bool operator!=(const Array& o) const { return !(*this == o); }

private:
    std::vector<std::size_t> shape_;
    std::vector<T> data_;
};
