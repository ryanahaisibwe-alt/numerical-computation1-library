#pragma once
#include <vector>
#include <stdexcept>

namespace hamza {

class Addition {
public:
    template <typename T>
    static std::vector<T> add(const std::vector<T>& a, const std::vector<T>& b) {
        if (a.size() != b.size()) {
            throw std::invalid_argument("Vector sizes must match for element-wise addition.");
        }
        
        std::vector<T> result(a.size());
        for (size_t i = 0; i < a.size(); ++i) {
            result[i] = a[i] + b[i];
        }
        return result;
    }
};

} // namespace hamza