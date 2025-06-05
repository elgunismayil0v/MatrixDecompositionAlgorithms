#include "MemoryManager.h"

MemoryManager::MemoryManager(const Matrix& a_) : matrix(a_) {};
MemoryManager::MemoryManager(const MemoryManager& other) : matrix(other.matrix) {};

MemoryManager& MemoryManager::operator=(const MemoryManager& other) {
    if(this != &other) {
        matrix = other.matrix;
    }

    return *this;
}