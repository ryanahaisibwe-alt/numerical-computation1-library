#include "Matrix.hpp"
#include <iostream>
#include <vector>

int main() {
    std::vector<double> temp = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
    
    // Create a 3x4 matrix
    Matrix mat(temp, 3, 4);

    std::cout << "--- Initial Matrix ---" << std::endl;
    mat.print_matrix();

    std::cout << "\nValue at row 1, col 2: " << mat.get_value(1, 2) << std::endl;

    std::cout << "\n--- Testing Slice (Rows 0-2, Cols 1-3) ---" << std::endl;
    Matrix sub = mat.extract_submatrix(0, 2, 1, 3);
    sub.print_matrix();

    return 0;
}
