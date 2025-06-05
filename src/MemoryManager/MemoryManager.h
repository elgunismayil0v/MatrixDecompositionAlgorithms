#ifndef MEMORY_MANAGER
#define MEMORY_MANAGER

#include <vector>
using namespace std;
typedef vector<vector<double>> Matrix;

class MemoryManager {
    public:
    MemoryManager(const Matrix& a_);
    MemoryManager(const MemoryManager& other);
    MemoryManager& operator=(const MemoryManager& other);
    ~MemoryManager(){};
    private:
    Matrix matrix;

};




#endif // MEMORY_MANAGER
