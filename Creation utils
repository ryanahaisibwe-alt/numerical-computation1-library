// creation_utils.hpp
// Array creation, concatenation and splitting  (Group 22 - Sooma)
//
// Conventions (to be confirmed with the group):
//   * Storage is flat, row-major, contiguous.
//   * Axes are 0-based; axis 0 = rows.
//   * Every dimension must be >= 1 (no empty arrays).
//   * All argument/shape errors throw std::invalid_argument.
//   * Every function returns a NEW array (copies); inputs are never modified.
#pragma once

#include <algorithm>
#include <cmath>
#include <cstddef>
#include <stdexcept>
#include <string>
#include <vector>

#include "array_stub.hpp"  // replace with the real Array header when available

namespace nc {

using Shape = std::vector<std::size_t>;

// ---------------------------------------------------------------------------
// Internal helpers
// ---------------------------------------------------------------------------
namespace detail {

inline void check_shape(const Shape& shape) {
    if (shape.empty())
        throw std::invalid_argument("shape must have at least one dimension");
    for (std::size_t d : shape)
        if (d == 0)
            throw std::invalid_argument("every dimension must be >= 1");
}

// Product of shape[from, to)
inline std::size_t product(const Shape& s, std::size_t from, std::size_t to) {
    std::size_t p = 1;
    for (std::size_t i = from; i < to; ++i) p *= s[i];
    return p;
}

// Copies `len` slices (starting at `start`) along `axis` out of `src`.
// Used by both split functions.
template <class T>
Array<T> slice_axis(const Array<T>& src, std::size_t axis,
                    std::size_t start, std::size_t len) {
    Shape out_shape = src.shape();
    const std::size_t n = out_shape[axis];
    out_shape[axis] = len;

    const std::size_t outer = product(src.shape(), 0, axis);
    const std::size_t inner = product(src.shape(), axis + 1, src.ndim());

    Array<T> out(out_shape);
    T* dst = out.data();
    for (std::size_t o = 0; o < outer; ++o) {
        const T* from = src.data() + (o * n + start) * inner;
        std::copy_n(from, len * inner, dst);
        dst += len * inner;
    }
    return out;
}

}  // namespace detail

// ---------------------------------------------------------------------------
// Creation
// ---------------------------------------------------------------------------

// Array of the given shape filled with `value`.
template <class T = double>
Array<T> full(const Shape& shape, T value) {
    detail::check_shape(shape);
    return Array<T>(shape, value);
}

template <class T = double>
Array<T> zeros(const Shape& shape) {
    return full<T>(shape, T(0));
}

template <class T = double>
Array<T> ones(const Shape& shape) {
    return full<T>(shape, T(1));
}

// Evenly spaced values in [start, stop) with the given step (1-D result).
// arange(0, 5, 2) -> [0, 2, 4];  arange(5, 0, -1) -> [5, 4, 3, 2, 1]
template <class T = double>
Array<T> arange(T start, T stop, T step = T(1)) {
    if (step == T(0))
        throw std::invalid_argument("arange: step must not be zero");

    const double len = std::ceil((static_cast<double>(stop) -
                                  static_cast<double>(start)) /
                                 static_cast<double>(step));
    if (!(len > 0.0))
        throw std::invalid_argument(
            "arange: range is empty (check start, stop and the sign of step)");

    const std::size_t n = static_cast<std::size_t>(len);
    Array<T> out({n});
    for (std::size_t i = 0; i < n; ++i)
        out[i] = static_cast<T>(start + static_cast<T>(i) * step);
    return out;
}

// `num` evenly spaced values from start to stop (1-D result).
// endpoint = true  -> stop is the last value
// endpoint = false -> stop is excluded
template <class T = double>
Array<T> linspace(T start, T stop, std::size_t num, bool endpoint = true) {
    if (num == 0)
        throw std::invalid_argument("linspace: num must be >= 1");

    Array<T> out({num});
    if (num == 1) {
        out[0] = start;
        return out;
    }
    const double divisor = static_cast<double>(endpoint ? num - 1 : num);
    const double step =
        (static_cast<double>(stop) - static_cast<double>(start)) / divisor;
    for (std::size_t i = 0; i < num; ++i)
        out[i] = static_cast<T>(static_cast<double>(start) +
                                static_cast<double>(i) * step);
    if (endpoint) out[num - 1] = stop;  // avoid rounding drift on the last value
    return out;
}

// n x n identity matrix.
template <class T = double>
Array<T> eye(std::size_t n) {
    if (n == 0) throw std::invalid_argument("eye: n must be >= 1");
    Array<T> out = zeros<T>({n, n});
    for (std::size_t i = 0; i < n; ++i) out[i * n + i] = T(1);
    return out;
}

// ---------------------------------------------------------------------------
// Concatenation
// ---------------------------------------------------------------------------

// Joins arrays along an existing axis. All arrays must have the same number of
// dimensions and identical sizes in every dimension except `axis`.
//
// Layout trick: view an array as [outer][shape[axis]][inner]. For each outer
// index, each input contributes one contiguous block of shape[axis]*inner
// elements, so the whole join is a series of block copies.
template <class T>
Array<T> concatenate(const std::vector<Array<T>>& arrs, std::size_t axis = 0) {
    if (arrs.empty())
        throw std::invalid_argument("concatenate: need at least one array");

    const Shape& first = arrs[0].shape();
    const std::size_t nd = first.size();
    if (axis >= nd)
        throw std::invalid_argument("concatenate: axis " + std::to_string(axis) +
                                    " is out of range for " +
                                    std::to_string(nd) + "-D arrays");

    Shape out_shape = first;
    out_shape[axis] = 0;
    for (std::size_t k = 0; k < arrs.size(); ++k) {
        const Shape& s = arrs[k].shape();
        if (s.size() != nd)
            throw std::invalid_argument(
                "concatenate: all arrays must have the same number of dimensions");
        for (std::size_t d = 0; d < nd; ++d)
            if (d != axis && s[d] != first[d])
                throw std::invalid_argument(
                    "concatenate: shapes differ in dimension " + std::to_string(d));
        out_shape[axis] += s[axis];
    }

    const std::size_t outer = detail::product(out_shape, 0, axis);
    const std::size_t inner = detail::product(out_shape, axis + 1, nd);

    Array<T> out(out_shape);
    T* dst = out.data();
    for (std::size_t o = 0; o < outer; ++o) {
        for (const Array<T>& a : arrs) {
            const std::size_t block = a.shape()[axis] * inner;
            std::copy_n(a.data() + o * block, block, dst);
            dst += block;
        }
    }
    return out;
}

// Stack along axis 0 (needs ndim >= 2).
template <class T>
Array<T> vstack(const std::vector<Array<T>>& arrs) {
    if (!arrs.empty() && arrs[0].ndim() < 2)
        throw std::invalid_argument("vstack: arrays must be at least 2-D");
    return concatenate(arrs, 0);
}

// Stack side by side: axis 1 for 2-D+ arrays, axis 0 for 1-D arrays.
template <class T>
Array<T> hstack(const std::vector<Array<T>>& arrs) {
    if (arrs.empty())
        throw std::invalid_argument("hstack: need at least one array");
    return concatenate(arrs, arrs[0].ndim() == 1 ? 0 : 1);
}

// ---------------------------------------------------------------------------
// Splitting
// ---------------------------------------------------------------------------

// Splits into `sections` equal parts along `axis`.
// Throws if the axis length is not divisible by `sections`.
template <class T>
std::vector<Array<T>> split(const Array<T>& arr, std::size_t sections,
                            std::size_t axis = 0) {
    if (axis >= arr.ndim())
        throw std::invalid_argument("split: axis out of range");
    if (sections == 0)
        throw std::invalid_argument("split: sections must be >= 1");
    const std::size_t n = arr.shape()[axis];
    if (n % sections != 0)
        throw std::invalid_argument("split: axis length " + std::to_string(n) +
                                    " is not divisible by " +
                                    std::to_string(sections));

    const std::size_t len = n / sections;
    std::vector<Array<T>> parts;
    parts.reserve(sections);
    for (std::size_t k = 0; k < sections; ++k)
        parts.push_back(detail::slice_axis(arr, axis, k * len, len));
    return parts;
}

// Splits at the given indices along `axis`.
// split_at(a, {3, 7}, 0) on a length-10 axis -> pieces [0,3) [3,7) [7,10).
// Indices must be strictly increasing and inside (0, axis length).
template <class T>
std::vector<Array<T>> split_at(const Array<T>& arr,
                               const std::vector<std::size_t>& indices,
                               std::size_t axis = 0) {
    if (axis >= arr.ndim())
        throw std::invalid_argument("split_at: axis out of range");
    const std::size_t n = arr.shape()[axis];

    std::size_t prev = 0;
    for (std::size_t idx : indices) {
        if (idx <= prev || idx >= n)
            throw std::invalid_argument(
                "split_at: indices must be strictly increasing and within (0, " +
                std::to_string(n) + ")");
        prev = idx;
    }

    std::vector<std::size_t> bounds;
    bounds.push_back(0);
    bounds.insert(bounds.end(), indices.begin(), indices.end());
    bounds.push_back(n);

    std::vector<Array<T>> parts;
    parts.reserve(bounds.size() - 1);
    for (std::size_t k = 0; k + 1 < bounds.size(); ++k)
        parts.push_back(
            detail::slice_axis(arr, axis, bounds[k], bounds[k + 1] - bounds[k]));
    return parts;
}

}  // namespace nc
