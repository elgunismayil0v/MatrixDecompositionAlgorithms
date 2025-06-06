#include <iostream>
#include "LU.h"




#include <iostream>
#include <vector>
#include <string>

using namespace std;


// Print flat matrix
void printMatrix(const FlatMatrix& M, int rows, int cols, const string& name) {
    cout << name << ":\n";
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j)
            cout << M(i, j) << "\t";
        cout << "\n";
    }
    cout << endl;
}

// Print permutation vector unchanged
void printPermutation(const vector<int>& P) {
    cout << "Permutation vector P:\n";
    for (int i : P)
        cout << i << " ";
    cout << "\n\n";
}

int main() {
    int rows = 3, cols = 3;

    FlatMatrix A(3, 3);
    A(0,0) = 2;  A(0,1) = 3;  A(0,2) = 1;
    A(1,0) = 4;  A(1,1) = 7;  A(1,2) = 2;
    A(2,0) = 6;  A(2,1) = 18; A(2,2) = -1;

    LU lu_decomp(A);
    lu_decomp.Compute();  // ✅ DON'T forget this!

    FlatMatrix L = lu_decomp.L();
    FlatMatrix U = lu_decomp.U();
    vector<int> P = lu_decomp.PermutationMatrix();

    printMatrix(A, rows, cols, "Original Matrix A");
    printMatrix(L, rows, cols, "Lower Matrix L");
    printMatrix(U, rows, cols, "Upper Matrix U");
    printPermutation(P);

    return 0;
}

