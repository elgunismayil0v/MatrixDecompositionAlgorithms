#ifndef SOLVER_H
#define SOLVER_H
#include <vector>

#include "Decomposition.h"
#include "FlatMatrix.h"
typedef std::vector<double> Vector;

class Solver {
    public:
    Solver(Decomposition* Dec, Vector& b_);
    Vector ForwardSubstitution();   
    Vector BackwardSubstitution();
    Vector Solve();
    ~Solver() = default;
    private:
    Decomposition* decomposition;
    Vector b;
    Vector y;
    Vector x;
};



#endif // SOLVER_H