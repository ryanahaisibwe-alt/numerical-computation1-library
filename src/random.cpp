#include "addition.hpp"
#include <random>

namespace numlib
{
    std::vector<double> random_uniform(size_t size, double min, double max) {
        std::vector<double> result(size);
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_real_distribution<double> dis(min, max);

        for (size_t i = 0; i < size; ++i) {
            result[i] = dis(gen);
        }
        return result;
    }
}
