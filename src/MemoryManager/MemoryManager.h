#ifndef MEMORY_MANAGER
#define MEMORY_MANAGER

#include <vector>
#include "FlatMatrix.h"
using namespace std;

class MemoryManager {
    public:
    MemoryManager(const FlatMatrix& a_);
    MemoryManager(const MemoryManager& other);
    MemoryManager& operator=(const MemoryManager& other);
    MemoryManager(MemoryManager&& other) noexcept;
    MemoryManager& operator=(MemoryManager&& other) noexcept;
    const FlatMatrix& getMatrix() const;
    ~MemoryManager(){};
    private:
    FlatMatrix matrix;

};




#endif // MEMORY_MANAGER
