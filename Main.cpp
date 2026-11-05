#include "MatrixSlice.hpp"
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int rows, cols;
    cout << "Enter matrix dimensions (Rows Columns): ";
    cin >> rows >> cols;

    int total = rows * cols;
    vector<double> input_data(total);

    cout << "Enter " << total << " values sequentially: " << endl;
    for (int i = 0; i < total; ++i) {
        cin >> input_data[i];
    }

    // Create the matrix
    MatrixSlice mat(input_data, rows, cols);

    cout << "\n--- Your Matrix ---" << endl;
    mat.print_matrix();

    // Quick Slice Example
    int start_r, end_r, start_c, end_c;
    cout << "\nEnter slice limits (start_row end_row start_col end_col): ";
    cin >> start_r >> end_r >> start_c >> end_c;

    cout << "\n--- Extracted Submatrix ---" << endl;
    MatrixSlice sub_mat = mat.extract_submatrix(start_r, end_r, start_c, end_c);
    sub_mat.print_matrix();

    return 0;
}
