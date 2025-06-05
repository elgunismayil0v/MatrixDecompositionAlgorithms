#ifndef DECOMPOSITION
#define DECOMPOSITION

#include "MemoryManager.h"
#include <vector>

using namespace std;
typedef vector<vector<double>> Matrix;
typedef vector<double> V;

class Decomposition{
    public:
    Decomposition(){};
    virtual Matrix operator()() = 0;
    virtual Decomposition* const clone() = 0;
    



};

#endif // DECOMPOSITION