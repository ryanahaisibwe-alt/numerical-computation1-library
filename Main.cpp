#include "MatrixSlice.hpp"
#include <iostream>
#include <vector>
using namespace std;
int main() {
    vector<double> list = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
    
    // Create a 3x4 matrix
    Matrixslice mat(list, 3, 4);

    cout << "--- Initial Matrix ---" << endl;
    mat.print_matrix();

    cout << "\nValue at row 1, col 2: " << mat.get_value(1, 2) << endl;

    cout << "\n--- Testing Slice (Rows 0-2, Cols 1-3) ---" << endl;
    MatrixSlice sub = mat.extract_submatrix(0, 2, 1, 3);
    sub.print_matrix();

    return 0;
}
