#include "MemoryManager.h"

MemoryManager::MemoryManager(const FlatMatrix& a_) : matrix(a_) {};
MemoryManager::MemoryManager(const MemoryManager& other) : matrix(other.matrix) {};

MemoryManager& MemoryManager::operator=(const MemoryManager& other) {
    if(this != &other) {
        matrix = other.matrix;
    }

    return *this;
}

MemoryManager::MemoryManager(MemoryManager&& other) noexcept : matrix(move(other.matrix)) {};

MemoryManager& MemoryManager::operator=(MemoryManager&& other) noexcept {
    if(this != &other) matrix = move(other.matrix);
    return *this;
}

const FlatMatrix& MemoryManager::getMatrix() const{
    return matrix;
}