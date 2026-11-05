
#pragma once

#include <vector>
using namespace std;

class MatrixSlice {
public:
    vector<double> data_buffer;
    int rows;
    int columns;

    // Constructor
    MatrixSlice(vector<double> input_data, int r, int c);

    // 1. Index Access
    double get_value(int r, int c);
    void set_value(int r, int c, double val);

    // 2. Reshape Matrix
    bool reshape_matrix(int new_row, int new_col);

    // 3. Extract part of the matrix
    // End row and end column are not included
    MatrixSlice extract_submatrix(
        int start_row,
        int end_row,
        int start_col,
        int end_col
    );

    // Print matrix contents
    void print_matrix() const;
};
