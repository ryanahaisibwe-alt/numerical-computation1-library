#include "Matrix.hpp"
#include <iostream>
#include <vector>

int main() {
    // -------------------------------------------------------------
    // INITIALIZATION EXAMPLE
    // -------------------------------------------------------------
    // Create a sequential vector from 1 to 12
    std::vector<double> initial_data = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
    
    // Instantiate a 3x4 Matrix (3 rows, 4 columns)
    Matrix mat(initial_data, 3, 4);

    std::cout << "=== 1. Initial 3x4 Matrix ===" << std::endl;
    mat.print_matrix();
    // Expected Output:
    // 1 2 3 4 
    // 5 6 7 8 
    // 9 10 11 12 

    // -------------------------------------------------------------
    // INDEX ACCESS & MODIFICATION EXAMPLE
    // -------------------------------------------------------------
    std::cout << "\n=== 2. Testing Indexing & Editing ===" << std::endl;
    
    // Read an individual value (Row 1, Column 2 -> should be 7)
    double value = mat.get_value(1, 2);
    std::cout << "Value at row 1, col 2 is: " << value << std::endl;

    // Modify a value within bounds
    std::cout << "Changing value at row 2, col 3 from 12 to 99.0..." << std::endl;
    mat.set_value(2, 3, 99.0);
    
    // Try accessing a value outside bounds to trigger your custom safety check
    std::cout << "Triggering safety boundary check:" << std::endl;
    mat.get_value(5, 1); 

    // -------------------------------------------------------------
    // RESHAPING EXAMPLE
    // -------------------------------------------------------------
    std::cout << "\n=== 3. Testing Reshape (3x4 to 2x6) ===" << std::endl;
    
    // A 3x4 layout (12 items) can easily convert to 2x6 (12 items)
    if (mat.reshape_matrix(2, 6)) {
        std::cout << "Reshaped Successfully!" << std::endl;
        mat.print_matrix();
        // Expected Output:
        // 1 2 3 4 5 6 
        // 7 8 9 10 11 99 
    }

    // Attempt an invalid reshape layout configuration
    std::cout << "\nAttempting an invalid reshape (to 5x5 layout)..." << std::endl;
    mat.reshape_matrix(5, 5); 

    // Resetting matrix back to 3x4 layout for the slice demo
    mat.reshape_matrix(3, 4);

    // -------------------------------------------------------------
    // SLICING EXAMPLE
    // -------------------------------------------------------------
    std::cout << "\n=== 4. Testing Matrix Slicing ===" << std::endl;
    std::cout << "Extracting rows 0-2 (0 and 1) and cols 1-3 (1 and 2):" << std::endl;
    
    // Grabs a rectangular inner section of your matrix buffer
    Matrix submatrix = mat.extract_submatrix(0, 2, 1, 3);
    submatrix.print_matrix();
    // Expected Output:
    // 2 3 
    // 6 7 

    return 0;
}
