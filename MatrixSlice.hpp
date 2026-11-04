#pragma once

#include <vector>
using namespace std;

class MatrixSlice {
public:
    vector<double> data_buffer; // Standard flat vector to store all the numbers
    int rows;
    int columns;

    // Constructor
    MatrixSlice (vector<double> input_data, int r, int c);

    // 1. Hand-written Index Access (Row-Major)
    double get_value(int r, int c);
    void set_value(int r, int c, double val);

    // 2. Simple Reshaping
    bool reshape_matrix(int new_row, int new_col);

    // 3. Manual Slicing using deep copy nested loops
    MatrixSlice extract_submatrix(int start_row, int end_row, int start_col, int end_col);

    // Quick helper to print contents
    void print_matrix();
};
