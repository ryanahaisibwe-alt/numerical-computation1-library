#include "MatrixSlice.hpp"
#include <iostream>
#include <vector>

using namespace std;

int main() {
    // 1. Creating a simple 4x4 image screen 
    int rows = 4;
    int cols = 4;
    
    // Fill it with 0.0 (acting as empty black pixels)
    vector<double> screen_pixels(rows * cols, 0.0);
    MatrixSlice screen(screen_pixels, rows, cols);

    // 2. Draw a diagonal line of "bright" pixels (value 1.0)
    screen.set_value(0, 0, 1.0);
    screen.set_value(1, 1, 1.0);
    screen.set_value(2, 2, 1.0);
    screen.set_value(3, 3, 1.0);

    cout << "=== Full 4x4 Screen Display ===" << endl;
    screen.print_matrix();

    // 3. User chooses which pixel region to focus on
    int start_r, end_r, start_c, end_c;
    cout << "\nCrop the image! Enter limits (start_row end_row start_col end_col): ";
    cin >> start_r >> end_r >> start_c >> end_c;

    // 4. Extract the cropped region using your slice logic
    cout << "\n=== Cropped Image Region ===" << endl;
    MatrixSlice cropped_region = screen.extract_submatrix(start_r, end_r, start_c, end_c);
    cropped_region.print_matrix();

    return 0;
}
