// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 4
// =============================================================================
//
// TASK: Matrix Operations
//
// Write a C++ program that performs three operations on matrices (2D arrays),
// each implemented in its own function.
//
// NOTE: Use a fixed maximum size of 10 for array dimensions.
//       Declare arrays as int matrix[10][10].
//
// -----------------------------------------------------------------------------
// PART A — Transpose a Matrix
// -----------------------------------------------------------------------------
// - Read an M x N matrix from the user.
// - Compute and display its transpose (rows become columns, columns become rows).
//
// Example (2 x 3 input):
//
//   Original Matrix:      Transposed Matrix:
//   1  2  3               1  4
//   4  5  6               2  5
//                         3  6
//
// -----------------------------------------------------------------------------
// PART B — Add Two Matrices
// -----------------------------------------------------------------------------
// - Read two matrices of exactly the same size (M x N).
// - Compute their element-wise sum and display the result.
//
// -----------------------------------------------------------------------------
// PART C — Multiply Two Matrices
// -----------------------------------------------------------------------------
// - Read matrix A of size M x N and matrix B of size N x P.
//   (Number of COLUMNS in A must equal number of ROWS in B.)
// - Compute and display the matrix product A x B (result is M x P).
//
// -----------------------------------------------------------------------------
// EXPECTED INPUT FORMAT
// -----------------------------------------------------------------------------
// The user enters each row's values one at a time:
//
//   Enter number of rows: 2
//   Enter number of columns: 3
//   Enter element [0][0]: 1
//   Enter element [0][1]: 2
//   ...
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Use nested loops for all operations (no external libraries).
// - Each operation must be in its own function (see scaffold below).
// - Display each matrix in a neat, aligned grid using setw().
// - Tip: Complete Part A first, then Parts B and C.
//

// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

#include <iostream>
#include <iomanip>
using namespace std;

const int MAX = 10;

// Function to read a matrix
void readMatrix(int matrix[][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << "Enter element [" << i << "][" << j << "]: ";
            cin >> matrix[i][j];
        }
    }
}

// Function to display a matrix
void displayMatrix(int matrix[][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << setw(5) << matrix[i][j];
        }
        cout << endl;
    }
}

// Part A: Transpose a matrix
void transposeMatrix(int matrix[][MAX], int result[][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[j][i] = matrix[i][j];
        }
    }
}

// Part B: Add two matrices
void addMatrices(int matrixA[][MAX], int matrixB[][MAX],
                 int result[][MAX], int rows, int cols) {

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = matrixA[i][j] + matrixB[i][j];
        }
    }
}

// Part C: Multiply two matrices
void multiplyMatrices(int matrixA[][MAX], int matrixB[][MAX],
                      int result[][MAX],
                      int rowsA, int colsA, int colsB) {

    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < colsB; j++) {
            result[i][j] = 0;

            for (int k = 0; k < colsA; k++) {
                result[i][j] += matrixA[i][k] * matrixB[k][j];
            }
        }
    }
}


int main() {

    // ---------------- PART A ----------------
    cout << "PART A - Transpose Matrix\n";

    int matrix[10][10];
    int transpose[10][10];

    int rows, cols;

    cout << "Enter number of rows: ";
    cin >> rows;

    cout << "Enter number of columns: ";
    cin >> cols;

    readMatrix(matrix, rows, cols);

    cout << "\nOriginal Matrix:\n";
    displayMatrix(matrix, rows, cols);

    transposeMatrix(matrix, transpose, rows, cols);

    cout << "\nTransposed Matrix:\n";
    displayMatrix(transpose, cols, rows);


    // ---------------- PART B ----------------
    cout << "\nPART B - Matrix Addition\n";

    int matrixA[10][10];
    int matrixB[10][10];
    int sum[10][10];

    cout << "Enter number of rows: ";
    cin >> rows;

    cout << "Enter number of columns: ";
    cin >> cols;

    cout << "\nEnter Matrix A:\n";
    readMatrix(matrixA, rows, cols);

    cout << "\nEnter Matrix B:\n";
    readMatrix(matrixB, rows, cols);

    addMatrices(matrixA, matrixB, sum, rows, cols);

    cout << "\nMatrix A + Matrix B:\n";
    displayMatrix(sum, rows, cols);


    // ---------------- PART C ----------------
    cout << "\nPART C - Matrix Multiplication\n";

    int matrixC[10][10];
    int product[10][10];

    int rowsA, colsA, rowsB, colsB;

    cout << "Enter rows of Matrix A: ";
    cin >> rowsA;

    cout << "Enter columns of Matrix A: ";
    cin >> colsA;

    cout << "\nEnter Matrix A:\n";
    readMatrix(matrixC, rowsA, colsA);

    cout << "Enter rows of Matrix B: ";
    cin >> rowsB;

    cout << "Enter columns of Matrix B: ";
    cin >> colsB;


    if (colsA != rowsB) {
        cout << "Error: Columns of Matrix A must equal rows of Matrix B."
             << endl;
        return 0;
    }

    cout << "\nEnter Matrix B:\n";
    readMatrix(matrixB, rowsB, colsB);

    multiplyMatrices(matrixC, matrixB, product,
                      rowsA, colsA, colsB);

    cout << "\nMatrix A x Matrix B:\n";
    displayMatrix(product, rowsA, colsB);

    return 0;
}
