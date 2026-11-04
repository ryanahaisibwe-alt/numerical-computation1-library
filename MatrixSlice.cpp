#include "MatrixSlice.hpp"
#include <iostream>

// Standard namespace directive as requested
using namespace std;

// Constructor for the vector.
MatrixSlice::MatrixSlice(std::vector<double> input_data, int r, int c) {
    data_buffer = input_data;
    rows = r;
    columns = c;
}

// 1. Hand-written Index Access (Row-Major: index = r * columns + c)
double MatrixSlice::get_value(int r, int c) {
    // checking if requested row is out of bounds
    if (r < 0 || r >= rows) {
        cout << "Row error: " << r << " is out of bounds!" << endl;
        return -1.0;
    }
    // checking if requested column is out-of-bounds 
    if (c < 0 || c >= columns) {
    cout << "Col error: " << c << " is out of bounds!" << endl;
     return 0;
    }

    // Map 2D coordinates to the underlying 1D flat buffer index
    int target_index = (r * columns) + c;
    return data_buffer[target_index];
}

// function  to modify an element
void MatrixSlice::set_value(int r, int c, double val) {
    // to ensure thst both row and column are within valid operational limits
    if (r >= 0 && r < rows && c >= 0 && c < columns) {
        data_buffer[(r * columns) + c] = val;
    } else {
        cout << "invalid inputs " << endl;
    }
}

// 2. Reshaping
bool MatrixSlice::reshape_matrix(int new_rows, int new_cols) {
    int current_total = rows * columns;
    int target_total = new_rows * new_cols;

    // Verify if total element capacity matches before allowing transformation
    if (current_total != target_total) {
        cout << "Reshape failed: total size doesn't match!" << endl;
        return false;
    }

    // Assign new grid geometric dimensions if true
    rows = new_rows;
    columns = new_cols;
    return true;
}

// 3. Manual Slicing using deep copy nested loops
MatrixSlice MatrixSlice::extract_submatrix(int start_row, int end_row, int start_col, int end_col) {
    // Boundary check to ensure subgrid requests fall entirely within current grid limits
    if (start_row < 0 || end_row > rows || start_col < 0 || end_col > columns || start_row >= end_row || start_col >= end_col) {
        cout << "Invalid slice bounds provided!" << endl;
        return MatrixSlice({}, 0, 0); 
    }

    vector<double> sliced_data;
    int new_rows = end_row - start_row;
    int new_cols = end_col - start_col;

    // Deep copy subset extraction loops
    for (int i = start_row; i < end_row; i++) {
    for (int j = start_col; j < end_col; j++) {
        
   // Translate original coordinate space to get source location index
    int old_index = (i * columns) + j;
    sliced_data.push_back(data_buffer[old_index]);
        }
    }

    // Return the newly constructed sub-grid instance
    return MatrixSlice(sliced_data, new_rows, new_cols);
}

// Quick helper to see what's inside
void MatrixSlice::print_matrix() {
    // Loop across rows and columns to output contents sequentially
for (int i = 0; i < rows; i++) {
 for (int j = 0; j < columns; j++) {
 cout << data_buffer[(i * columns) + j] << " ";
        }
        cout << endl; 
}
