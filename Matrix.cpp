#include "Matrix.hpp"
#include <iostream>

// Constructor for a flat 1D vector or basic layout
Matrix::Matrix(std::vector<double> input_data, int r, int c) {
    data_buffer = input_data;
    rows = r;
    columns = c;
}

// 1. Hand-written Index Access (Row-Major: index = r * columns + c)
double Matrix::get_value(int r, int c) {
    if (r < 0 || r >= rows) {
        std::cout << "Row error: " << r << " is out of bounds!" << std::endl;
        return -1.0;
    }
    if (c < 0 || c >= columns) {
        std::cout << "Col error: " << c << " is out of bounds!" << std::endl;
        return -1.0;
    }

    int target_index = (r * columns) + c;
    return data_buffer[target_index];
}

// Easy way to modify an element
void Matrix::set_value(int r, int c, double val) {
    if (r >= 0 && r < rows && c >= 0 && c < columns) {
        data_buffer[(r * columns) + c] = val;
    } else {
        std::cout << "Cannot set value, index invalid." << std::endl;
    }
}

// 2. Simple Reshaping
bool Matrix::reshape_matrix(int new_rows, int new_cols) {
    int current_total = rows * columns;
    int target_total = new_rows * new_cols;

    if (current_total != target_total) {
        std::cout << "Reshape failed: total size doesn't match!" << std::endl;
        return false;
    }

    rows = new_rows;
    columns = new_cols;
    return true;
}

// 3. Manual Slicing using deep copy nested loops
Matrix Matrix::extract_submatrix(int start_row, int end_row, int start_col, int end_col) {
    if (start_row < 0 || end_row > rows || start_col < 0 || end_col > columns || start_row >= end_row || start_col >= end_col) {
        std::cout << "Invalid slice bounds provided!" << std::endl;
        return Matrix({}, 0, 0); // Corrected from SharifPart
    }

    std::vector<double> sliced_data;
    int new_rows = end_row - start_row;
    int new_cols = end_col - start_col;

    for (int i = start_row; i < end_row; i++) {
        for (int j = start_col; j < end_col; j++) {
            int old_index = (i * columns) + j;
            sliced_data.push_back(data_buffer[old_index]);
        }
    }

    return Matrix(sliced_data, new_rows, new_cols);
}

// Quick helper to see what's inside
void Matrix::print_matrix() {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            std::cout << data_buffer[(i * columns) + j] << " ";
        }
        std::cout << std::endl;
    }
}
