#include <iostream>
using namespace std;

// PART C - IMAGE GRID PROCESSING

void displayMatrix(int mat[][4], int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << mat[i][j] << "\t";
        }
        cout << endl;
    }
}

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

double averageMatrix(int mat[][4], int rows, int cols)
{
    return (double)sumMatrix(mat, rows, cols) / (rows * cols);
}

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

int countAboveThreshold(int mat[][4], int rows, int cols, int threshold)
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

// PART D - MATRIX ADDITION

void addMatrices(int a[][3], int b[][3], int result[][3],
                 int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            result[i][j] = a[i][j] + b[i][j];
        }
    }
}

// PART E - MATRIX SUBTRACTION

void subtractMatrices(int a[][3], int b[][3], int result[][3],
                      int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            result[i][j] = a[i][j] - b[i][j];
        }
    }
}

// PART F & G - MATRIX MULTIPLICATION

bool multiplyMatrices(int a[][3], int b[][3], int result[][3],
                      int rowsA, int colsA, int rowsB, int colsB)
{
    if (colsA != rowsB)
    {
        cout << "Matrix multiplication cannot be performed." << endl;
        return false;
    }

    for (int i = 0; i < rowsA; i++)
    {
        for (int j = 0; j < colsB; j++)
        {
            result[i][j] = 0;

            for (int k = 0; k < colsA; k++)
            {
                result[i][j] += a[i][k] * b[k][j];
            }
        }
    }

    return true;
}

// MAIN PROGRAM - PART H

int main()
{
    // PART C - 4x4 IMAGE GRID

    int image[4][4] =
    {
        {50, 100, 150, 200},
        {25, 75, 125, 175},
        {0, 64, 128, 255},
        {30, 90, 180, 220}
    };

    int threshold = 128;

    cout << "       PART C - IMAGE PROCESSOR" << endl;

    cout << "\nImage Grid:" << endl;
    displayMatrix(image, 4, 4);

    cout << "\nTotal Brightness: "
         << sumMatrix(image, 4, 4) << endl;

    cout << "Average Brightness: "
         << averageMatrix(image, 4, 4) << endl;

    cout << "Maximum Brightness: "
         << findMaximum(image, 4, 4) << endl;

    cout << "Minimum Brightness: "
         << findMinimum(image, 4, 4) << endl;

    cout << "Brightness Threshold: "
         << threshold << endl;

    cout << "Pixels Above Threshold: "
         << countAboveThreshold(image, 4, 4, threshold) << endl;

    // PART D & E - MATRIX ADDITION AND SUBTRACTION

    int A[3][3] =
    {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int B[3][3] =
    {
        {9, 8, 7},
        {6, 5, 4},
        {3, 2, 1}
    };

    int sum[3][3];
    int difference[3][3];

    addMatrices(A, B, sum, 3, 3);
    subtractMatrices(A, B, difference, 3, 3);

    cout << "       PART D - MATRIX ADDITION" << endl;

    cout << "\nMatrix A:" << endl;
    displayMatrix(A, 3, 3);

    cout << "\nMatrix B:" << endl;
    displayMatrix(B, 3, 3);

    cout << "\nA + B:" << endl;
    displayMatrix(sum, 3, 3);

    cout << "     PART E - MATRIX SUBTRACTION" << endl;

    cout << "\nA - B:" << endl;
    displayMatrix(difference, 3, 3);

    subtractMatrices(B, A, difference, 3, 3);

    cout << "\nB - A:" << endl;
    displayMatrix(difference, 3, 3);


    // PART F - 2x2 MATRIX MULTIPLICATION

    int M1[3][3] =
    {
        {1, 2, 0},
        {3, 4, 0},
        {0, 0, 0}
    };

    int M2[3][3] =
    {
        {5, 6, 0},
        {7, 8, 0},
        {0, 0, 0}
    };

    int product[3][3];

    cout << "     PART F - MATRIX MULTIPLICATION" << endl;

    cout << "\nMatrix M1:" << endl;
    displayMatrix(M1, 2, 2);

    cout << "\nMatrix M2:" << endl;
    displayMatrix(M2, 2, 2);

    if (multiplyMatrices(M1, M2, product, 2, 2, 2, 2))
    {
        cout << "\nM1 x M2:" << endl;
        displayMatrix(product, 2, 2);
    }

    int C[3][3] =
    {
        {1, 2, 3},
        {4, 5, 6},
        {0, 0, 0}
    };

    int D[3][3] =
    {
        {7, 8, 0},
        {9, 10, 0},
        {11, 12, 0}
    };

    int product2[3][3];

    cout << "       2x3 x 3x2 TEST CASE" << endl;

    cout << "\nMatrix C (2x3):" << endl;
    displayMatrix(C, 2, 3);

    cout << "\nMatrix D (3x2):" << endl;
    displayMatrix(D, 3, 2);

    if (multiplyMatrices(C, D, product2, 2, 3, 3, 2))
    {
        cout << "\nC x D (2x2):" << endl;
        displayMatrix(product2, 2, 2);
    }

    // PART G - INCOMPATIBLE DIMENSIONS TEST

    int E[3][3] =
    {
        {1, 2, 3},
        {4, 5, 6},
        {0, 0, 0}
    };

    int F[3][3] =
    {
        {1, 2, 0},
        {3, 4, 0},
        {0, 0, 0}
    };

    int product3[3][3];

    cout << "     INCOMPATIBLE DIMENSION TEST" << endl;

    cout << "\nTrying to multiply 2x3 by 2x2..." << endl;

    multiplyMatrices(E, F, product3, 2, 3, 2, 2);

    // PART G - IDENTITY MATRIX SANITY CHECK

    int original[3][3] =
    {
        {2, 4, 6},
        {1, 3, 5},
        {7, 8, 9}
    };

    int identity[3][3] =
    {
        {1, 0, 0},
        {0, 1, 0},
        {0, 0, 1}
    };

    int identityResult[3][3];

    cout << "       IDENTITY MATRIX TEST" << endl;
    cout << "\nOriginal Matrix:" << endl;
    displayMatrix(original, 3, 3);

    cout << "\nIdentity Matrix:" << endl;
    displayMatrix(identity, 3, 3);

    if (multiplyMatrices(original, identity, identityResult, 3, 3, 3, 3))
    {
        cout << "\nOriginal x Identity:" << endl;
        displayMatrix(identityResult, 3, 3);
    }

    // END OF PROGRAM

    cout << "\n========================================" << endl;
    cout << "       PROGRAM COMPLETED" << endl;
    cout << "========================================" << endl;

    return 0;
}
