#ifndef LU_DECOMPOSITION
#define LU_DECOMPOSITION

#include "Decomposition.h"
#include <vector>

using namespace std;
typedef vector<double> Vector;

class LU : public Decomposition {
    public:
    LU(const FlatMatrix& a);
    void Compute() override;
    double Determinant() const override;
    vector<int> PermutationMatrix() const;
    FlatMatrix L() const;
    FlatMatrix U() const;
    Decomposition* clone() const override;
    ~LU() override = default;
    private:
    FlatMatrix a;
    FlatMatrix lu;
    Vector vv;
    vector<int> perm;
    int n;
    double d;
};

#endif // LU_DECOMPOSITION