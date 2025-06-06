#include <iostream>
#include <vector>
#include <cmath>
#include <stdexcept>
#include <algorithm>
#include "LU.h"

using namespace std;


LU::LU(const FlatMatrix& a_): Decomposition(a_), a(a_), n(a_.rows()), lu(a_) {
    lu = a;
    perm.resize(n);
    for (int i = 0; i < n; ++i) perm[i] = i;
    vv.resize(n);
};

void LU::Compute() {

    d = 1.0;
    const double TINY = 1e-40;

    // Row scaling
    for(int i = 0; i < n; i++){
        double big = 0.0;
        for(int j = 0; j < n; j++) big = max(big, fabs(lu(i,j)));
        if(big == 0) throw runtime_error("Singular Matrix");
        vv[i] = 1 / big;
    }

    // Decomposition with partial pivoting
    for(int k = 0; k < n; k++) {
        double big = 0.0;
        int imax = k;
        for(int i = k; i < n; i++){
        double temp = vv[i] * fabs(lu(i,k));
        if(temp > big) big = temp, imax = i;
        } 

        if(imax != k) {
            for(int j = 0; j < n; j++) swap(lu(k, j), lu(imax, j));
            swap(perm[k], perm[imax]);
            d = -d;
            vv[imax] = vv[k];
        }

        if(TINY > fabs(lu(k, k))) lu(k, k) = TINY;

        for(int i = k + 1; i < n; i++) {
            double factor = lu(i, k) /= lu(k, k);
            for(int j = k + 1; j < n; j++) {
                lu(i, j) -= factor * lu(k, j);

            }

        }


    }
}

FlatMatrix LU::L() const{
    FlatMatrix L(n, n);
    for(int i = 0; i < n; i++){
        L(i, i) = 1;
        for(int j = 0; j < i; j++){
            L(i, j) = lu(i, j);
        }
    }
    return L;

}

FlatMatrix LU::U() const {
    FlatMatrix U(n, n);
    for(int i = 0; i < n; i++) {
        for(int j = i; j < n; j++){
            U(i, j) = lu(i, j);
        }
    }
    return U;
}

vector<int> LU::PermutationMatrix() const {
    return perm;
}

double LU::Determinant() const {
    double determinant = d;
    for(int i = 0; i < n; i++){
        determinant *= lu(i, i);
    }
    return determinant;

}

Decomposition* LU::clone() const {
    return new LU(*this);
}