#include <vector>

using namespace std;
typedef vector<vector<double>> Matrix;
typedef vector<double> V;

class LU {
    public:
    LU(const Matrix& a);
    virtual Matrix operator()();
    



};