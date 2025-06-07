#include <iostream>
#include <vector>
#include <string>

#include "LU.h"
#include "Solver.h"

using namespace std;

void printMatrix(const FlatMatrix& M, int rows, int cols, const string& name) {
    cout << name << ":\n";
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j)
            cout << M(i, j) << "\t";
        cout << "\n";
    }
    cout << endl;
}

void printPermutation(const vector<int>& P) {
    cout << "Permutation vector P:\n";
    for (int i : P)
        cout << i << " ";
    cout << "\n\n";
}

void printVector(const Vector& v, const string& name) {
    cout << name << ":\n";
    for (double val : v)
        cout << val << "\n";
    cout << endl;
}

int main() {
    int rows = 3, cols = 3;

    // Define matrix A
    FlatMatrix A(3, 3);
    A(0,0) = 2;  A(0,1) = 3;  A(0,2) = 1;
    A(1,0) = 4;  A(1,1) = 7;  A(1,2) = 2;
    A(2,0) = 6;  A(2,1) = 18; A(2,2) = -1;

    // Define right-hand side vector b
    Vector b = {1, 2, 3};  // Ax = b

    // LU decomposition
    LU lu_decomp(A);
    lu_decomp.Compute();

    FlatMatrix L = lu_decomp.L();
    FlatMatrix U = lu_decomp.U();
    vector<int> P = lu_decomp.PermutationMatrix();

    // Print decomposition results
    printMatrix(A, rows, cols, "Original Matrix A");
    printMatrix(L, rows, cols, "Lower Matrix L");
    printMatrix(U, rows, cols, "Upper Matrix U");
    printPermutation(P);

    // Solve the system
    Solver solver(&lu_decomp, b);
    Vector x = solver.Solve();

    printVector(b, "Right-hand side b");
    printVector(x, "Solution x");

    return 0;
}


