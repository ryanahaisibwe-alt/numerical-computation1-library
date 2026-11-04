#pragma once
#include <vector>

namespace numlib
{
    std::vector<double> add(const std::vector<double>& a, const std::vector<double>& b);
    std::vector<double> subtract(const std::vector<double>& a, const std::vector<double>& b);
    std::vector<double> multiply(const std::vector<double>& a, const std::vector<double>& b);
    std::vector<double> divide(const std::vector<double>& a, const std::vector<double>& b);
    std::vector<bool> greater_than(const std::vector<double>& a, const std::vector<double>& b);
    std::vector<bool> less_than(const std::vector<double>& a, const std::vector<double>& b);

    double dot(const std::vector<double>& a, const std::vector<double>& b);
    std::vector<double> matmul(const std::vector<double>& matrix, const std::vector<double>& vec, size_t rows, size_t cols);

    std::vector<double> random_uniform(size_t size, double min = 0.0, double max = 1.0);
}
