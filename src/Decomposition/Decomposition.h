#ifndef DECOMPOSITION
#define DECOMPOSITION

#include "MemoryManager.h"
#include "FlatMatrix.h"
#include <vector>

using namespace std;

class Decomposition{
    public:
    Decomposition(const FlatMatrix& matrix): mem(matrix) {};
    virtual void Compute() = 0;
    virtual double Determinant() const = 0;
    virtual FlatMatrix L() const = 0;
    virtual FlatMatrix U() const = 0;
    virtual vector<int> PermutationMatrix() const = 0;
    virtual Decomposition* clone() const = 0;
    virtual ~Decomposition() = default;
    private:
    MemoryManager mem;
};

#endif // DECOMPOSITION