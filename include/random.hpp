#pragma once
#include <vector>
#include <random>
#include <type_traits>

namespace hamza {

class Random {
private:
    mutable std::mt19937 engine_;

public:
    explicit Random(unsigned int seed = 1337) : engine_(seed) {}

    template <typename T>
    std::vector<T> uniform(size_t size, T min_val = T{0}, T max_val = T{1}) {
        std::vector<T> result(size);
        if constexpr (std::is_integral_v<T>) {
            std::uniform_int_distribution<T> dist(min_val, max_val);
            for (size_t i = 0; i < size; ++i) {
                result[i] = dist(engine_);
            }
        } else {
            std::uniform_real_distribution<T> dist(min_val, max_val);
            for (size_t i = 0; i < size; ++i) {
                result[i] = dist(engine_);
            }
        }
        return result;
    }
};

} // namespace hamza