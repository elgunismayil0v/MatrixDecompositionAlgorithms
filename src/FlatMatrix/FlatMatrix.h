#ifndef FLAT_MATRIX
#define FLAT_MATRIX

#include <vector>

using namespace std;
typedef vector<double> Vector;

class FlatMatrix {
    public:
    FlatMatrix(size_t rows, size_t cols): m(rows), n(cols), data(m * n, 0.0) {};

    // Rule of 5
    FlatMatrix(const FlatMatrix& other) = default;
    FlatMatrix& operator=(const FlatMatrix& other) = default;
    FlatMatrix(FlatMatrix&& other) noexcept = default;
    FlatMatrix& operator=(FlatMatrix&& other) noexcept = default;
    ~FlatMatrix() = default;

    double& operator()(size_t i, size_t j) {return data[i * n + j];};
    double operator()(size_t i, size_t j) const {return data[i * n + j];};

    size_t rows() const { return m;};
    size_t cols() const { return n;};
    const Vector& raw() const { return data;};

    private:
    size_t m,n;
    Vector data;
};




#endif // FLAT_MATRIX