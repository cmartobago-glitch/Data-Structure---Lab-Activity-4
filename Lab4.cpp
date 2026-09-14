#include <iostream>
using namespace std;

// ============================================================
// PART C - IMAGE GRID PROCESSING
// ============================================================

// Displays a matrix.
void displayMatrix(int mat[][4], int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << mat[i][j] << "\t";
        }
        cout << "\n";
    }
}

// Calculates the total value of all elements.
int sumMatrix(int mat[][4], int rows, int cols)
{
    int total = 0;

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            total += mat[i][j];
        }
    }

    return total;
}

// Calculates the average value of all elements.
double averageMatrix(int mat[][4], int rows, int cols)
{
    return static_cast<double>(sumMatrix(mat, rows, cols))
           / (rows * cols);
}

// Finds the largest value in the matrix.
int findMaximum(int mat[][4], int rows, int cols)
{
    int maximum = mat[0][0];

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (mat[i][j] > maximum)
            {
                maximum = mat[i][j];
            }
        }
    }

    return maximum;
}

// Finds the smallest value in the matrix.
int findMinimum(int mat[][4], int rows, int cols)
{
    int minimum = mat[0][0];

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (mat[i][j] < minimum)
            {
                minimum = mat[i][j];
            }
        }
    }

    return minimum;
}

// Counts the number of values above the threshold.
int countAboveThreshold(
    int mat[][4],
    int rows,
    int cols,
    int threshold)
{
    int count = 0;

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (mat[i][j] > threshold)
            {
                count++;
            }
        }
    }

    return count;
}


// ============================================================
// PART D - MATRIX ADDITION
// ============================================================

// Adds two matrices of the same dimensions.
void addMatrices(
    int a[][4],
    int b[][4],
    int result[][4],
    int rows,
    int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            result[i][j] = a[i][j] + b[i][j];
        }
    }
}


// ============================================================
// PART E - MATRIX SUBTRACTION
// ============================================================

// Subtracts matrix B from matrix A.
void subtractMatrices(
    int a[][4],
    int b[][4],
    int result[][4],
    int rows,
    int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            result[i][j] = a[i][j] - b[i][j];
        }
    }
}


// ============================================================
// PART F & G - MATRIX MULTIPLICATION
// ============================================================

// Multiplies Matrix A by Matrix B.
//
// A = rowsA x colsA
// B = rowsB x colsB
//
// Multiplication is possible only when:
// colsA == rowsB
//
// Result = rowsA x colsB
bool multiplyMatrices(
    int a[][4],
    int b[][4],
    int result[][4],
    int rowsA,
    int colsA,
    int rowsB,
    int colsB)
{
    // PART G - Dimension Validation

    if (colsA != rowsB)
    {
        cout << "Matrix multiplication cannot be performed.\n";
        return false;
    }

    // i selects the row of Matrix A.
    for (int i = 0; i < rowsA; i++)
    {
        // j selects the column of Matrix B.
        for (int j = 0; j < colsB; j++)
        {
            // Start each result cell at zero.
            result[i][j] = 0;

            // k represents the shared dimension.
            for (int k = 0; k < colsA; k++)
            {
                result[i][j] += a[i][k] * b[k][j];
            }
        }
    }

    return true;
}


// ============================================================
// MAIN PROGRAM - PART H
// ============================================================

int main()
{
    // ========================================================
    // PART C - 4x4 IMAGE GRID
    // ========================================================

    int image[4][4] =
    {
        {50, 100, 150, 200},
        {25, 75, 125, 175},
        {0, 64, 128, 255},
        {30, 90, 180, 220}
    };

    int threshold = 128;

    cout << "========================================\n";
    cout << "       PART C - IMAGE PROCESSOR\n";
    cout << "========================================\n";

    cout << "\nImage Grid:\n";
    displayMatrix(image, 4, 4);

    cout << "\nTotal Brightness: "
         << sumMatrix(image, 4, 4) << "\n";

    cout << "Average Brightness: "
         << averageMatrix(image, 4, 4) << "\n";

    cout << "Maximum Brightness: "
         << findMaximum(image, 4, 4) << "\n";

    cout << "Minimum Brightness: "
         << findMinimum(image, 4, 4) << "\n";

    cout << "Brightness Threshold: "
         << threshold << "\n";

    cout << "Pixels Above Threshold: "
         << countAboveThreshold(image, 4, 4, threshold) << "\n";


    // ========================================================
    // PART D - MATRIX ADDITION
    // ========================================================

    int A[3][4] =
    {
        {1, 2, 3, 0},
        {4, 5, 6, 0},
        {7, 8, 9, 0}
    };

    int B[3][4] =
    {
        {9, 8, 7, 0},
        {6, 5, 4, 0},
        {3, 2, 1, 0}
    };

    int sum[3][4];

    addMatrices(A, B, sum, 3, 3);

    cout << "\n========================================\n";
    cout << "       PART D - MATRIX ADDITION\n";
    cout << "========================================\n";

    cout << "\nMatrix A:\n";
    displayMatrix(A, 3, 3);

    cout << "\nMatrix B:\n";
    displayMatrix(B, 3, 3);

    cout << "\nA + B:\n";
    displayMatrix(sum, 3, 3);


    // ========================================================
    // PART E - MATRIX SUBTRACTION
    // ========================================================

    int difference[3][4];

    subtractMatrices(A, B, difference, 3, 3);

    cout << "\n========================================\n";
    cout << "     PART E - MATRIX SUBTRACTION\n";
    cout << "========================================\n";

    cout << "\nA - B:\n";
    displayMatrix(difference, 3, 3);

    // Demonstrates that subtraction order matters.
    subtractMatrices(B, A, difference, 3, 3);

    cout << "\nB - A:\n";
    displayMatrix(difference, 3, 3);


    // ========================================================
    // PART F - 2x2 MATRIX MULTIPLICATION
    // ========================================================

    int M1[4][4] =
    {
        {1, 2, 0, 0},
        {3, 4, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0}
    };

    int M2[4][4] =
    {
        {5, 6, 0, 0},
        {7, 8, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0}
    };

    int product[4][4];

    cout << "\n========================================\n";
    cout << "     PART F - MATRIX MULTIPLICATION\n";
    cout << "========================================\n";

    cout << "\nMatrix M1:\n";
    displayMatrix(M1, 2, 2);

    cout << "\nMatrix M2:\n";
    displayMatrix(M2, 2, 2);

    if (multiplyMatrices(M1, M2, product, 2, 2, 2, 2))
    {
        cout << "\nM1 x M2:\n";
        displayMatrix(product, 2, 2);
    }


    // ========================================================
    // REQUIRED TEST CASE 2
    // 2x3 x 3x2
    // ========================================================

    int C[3][4] =
    {
        {1, 2, 3, 0},
        {4, 5, 6, 0},
        {0, 0, 0, 0}
    };

    int D[3][4] =
    {
        {7, 8, 0, 0},
        {9, 10, 0, 0},
        {11, 12, 0, 0}
    };

    int product2[4][4];

    cout << "\n========================================\n";
    cout << "       2x3 x 3x2 TEST CASE\n";
    cout << "========================================\n";

    cout << "\nMatrix C (2x3):\n";
    displayMatrix(C, 2, 3);

    cout << "\nMatrix D (3x2):\n";
    displayMatrix(D, 3, 2);

    if (multiplyMatrices(C, D, product2, 2, 3, 3, 2))
    {
        cout << "\nC x D:\n";
        displayMatrix(product2, 2, 2);
    }


    // ========================================================
    // PART G - INCOMPATIBLE DIMENSION TEST
    // ========================================================

    int E[3][4] =
    {
        {1, 2, 3, 0},
        {4, 5, 6, 0},
        {0, 0, 0, 0}
    };

    int F[3][4] =
    {
        {1, 2, 0, 0},
        {3, 4, 0, 0},
        {0, 0, 0, 0}
    };

    int product3[4][4];

    cout << "\n========================================\n";
    cout << "     INCOMPATIBLE DIMENSION TEST\n";
    cout << "========================================\n";

    cout << "\nTrying to multiply 2x3 by 2x2...\n";

    multiplyMatrices(E, F, product3, 2, 3, 2, 2);


    // ========================================================
    // IDENTITY MATRIX SANITY CHECK
    // ========================================================

    int original[3][4] =
    {
        {2, 4, 6, 0},
        {1, 3, 5, 0},
        {7, 8, 9, 0}
    };

    int identity[3][4] =
    {
        {1, 0, 0, 0},
        {0, 1, 0, 0},
        {0, 0, 1, 0}
    };

    int identityResult[4][4];

    cout << "\n========================================\n";
    cout << "       IDENTITY MATRIX TEST\n";
    cout << "========================================\n";

    cout << "\nOriginal Matrix:\n";
    displayMatrix(original, 3, 3);

    cout << "\nIdentity Matrix:\n";
    displayMatrix(identity, 3, 3);

    if (multiplyMatrices(
            original,
            identity,
            identityResult,
            3,
            3,
            3,
            3))
    {
        cout << "\nOriginal x Identity:\n";
        displayMatrix(identityResult, 3, 3);
    }


    // ========================================================
    // END OF PROGRAM
    // ========================================================

    cout << "\n========================================\n";
    cout << "       PROGRAM COMPLETED\n";
    cout << "========================================\n";

    return 0;
}
