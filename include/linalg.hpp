#pragma once
#include <vector>
#include <numeric>
#include <stdexcept>
#include <cmath>

namespace hamza {

class Linalg {
public:
    template <typename T>
    static T dot(const std::vector<T>& a, const std::vector<T>& b) {
        if (a.size() != b.size()) {
            throw std::invalid_argument("Vectors must have the same size for dot product.");
        }
        return std::inner_product(a.begin(), a.end(), b.begin(), T{0});
    }

    template <typename T>
    static T norm(const std::vector<T>& a) {
        T sum_sq = 0;
        for (const auto& val : a) {
            sum_sq += val * val;
        }
        return std::sqrt(sum_sq);
    }
};

} // namespace hamza