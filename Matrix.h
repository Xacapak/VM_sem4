#pragma once

#include <vector>

class Matrix {
public:
    std::vector<std::vector<double>> data;
    int rows, cols;

    Matrix(int rows, int cols);
    void setBlock(int startRow, int startCol, const Matrix& block);
    Matrix getInverse();
    void display() const;
};