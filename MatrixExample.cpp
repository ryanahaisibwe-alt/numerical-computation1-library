#include "Matrix.hpp"
#include <iostream>
#include <vector>
using namespace std;
int main() {

    // INITIALIZATION EXAMPLE

    std::vector<double> initial_data = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
    
    // consider a 3x4 Matrix (3 rows, 4 columns)
    Matrix mat(initial_data, 3, 4);

    cout << "=== Initial 3x4 Matrix ===" << endl;
    mat.print_matrix();
    // Expected Output:
    // 1 2 3 4 
    // 5 6 7 8 
    // 9 10 11 12 

    // INDEX ACCESS & MODIFICATION EXAMPLE

    cout << "\n=== Testing Indexing & Editing ===" << endl;
    
    // Read an individual value (Row 1, Column 2 -> should be 7)
    double value = mat.get_value(1, 2);
    cout << "Value at row 1, col 2 is: " << value << endl;

    // Modifying a value within bounds
    cout << "Changing value at row 2, col 3 from 12 to 99.0..." << endl;
    mat.set_value(2, 3, 99.0);
    
    // Trying to access a value outside bounds to test the safety check
    cout << "Triggering safety boundary check:" << endl;
    mat.get_value(5, 1); 

    // RESHAPING EXAMPLE

    cout << "\n=== 3. Testing Reshape (3x4 to 2x6) ===" << endl;
    
    // A 3x4 layout with 12 elements can easily convert to 2x6 
    if (mat.reshape_matrix(2, 6)) {
        cout << "Reshaped Successfully!" << endl;
        mat.print_matrix();
        // Expected Output:
        // 1 2 3 4 5 6 
        // 7 8 9 10 11 12
    }

    // Attempt an invalid reshape layout configuration e.g a 5 × 5
    cout << "\nAttempting an invalid reshape." << endl;
    mat.reshape_matrix(5, 5); 

    // Resetting matrix back to 3x4 layout for the slice demo
    mat.reshape_matrix(3, 4);

    // SLICING EXAMPLE
    
    cout << "\n=== 4. Testing Matrix Slicing ===" << endl;
    cout << "Extracting rows 0-2 (0 and 1) and cols 1-3 (1 and 2):" << endl;
    
    // Grabs a rectangular inner section of your matrix buffer
    Matrix submatrix = mat.extract_submatrix(0, 2, 1, 3);
    submatrix.print_matrix();
    // Expected Output:
    // 2 3 
    // 6 7 

    return 0;
}
