#include <stdexcept>
#include <vector>
#include "Solver.h"

using namespace std;

Solver::Solver(Decomposition* Dec, Vector& b_): decomposition(Dec), b(b_) {};


Vector Solver::ForwardSubstitution() {
    FlatMatrix Lower = decomposition->L();
    int rows = Lower.rows();
    if (b.size() != rows)
        throw runtime_error("Size mismatch in ForwardSubstitution");

    x = Vector(rows);
    vector<int> perm = decomposition->PermutationMatrix();

    for (int i = 0; i < rows; ++i) {
        double sum = b[perm[i]];
        for (int j = 0; j < i; ++j) {
            sum -= Lower(i, j) * x[j];
        }
        x[i] = sum;
    }

    return x;
}

Vector Solver::BackwardSubstitution() {
    FlatMatrix Upper = decomposition->U();
    int n = Upper.rows();
    Vector result = x;  // Assume x has the result from forward substitution

    for (int i = n - 1; i >= 0; --i) {
        double sum = result[i];
        for (int j = i + 1; j < n; ++j) {
            sum -= Upper(i, j) * result[j];
        }

        if (Upper(i, i) == 0.0)
            throw runtime_error("Division by zero in BackwardSubstitution");

        result[i] = sum / Upper(i, i);
    }

    return result;
}


Vector Solver::Solve() {
    y = ForwardSubstitution();
    x = BackwardSubstitution();
    return x;
}