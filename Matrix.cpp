#include "Matrix.h"
#include <iostream>
#include <stdexcept>

Matrix::Matrix(int rows, int cols) : rows(rows), cols(cols), data(rows, std::vector<double>(cols, 0)) {}

void Matrix::setBlock(int startRow, int startCol, const Matrix& block) {

    for (int i = 0; i < block.rows; ++i) {
        for (int j = 0; j < block.cols; ++j) {
            if (startRow + i >= rows || startCol + j >= cols) {
                throw std::out_of_range("Block position is out of the matrix bounds.");
            }
            data[startRow + i][startCol + j] = block.data[i][j];
        }
    }   
}

Matrix Matrix::getInverse() {
    if (rows != cols) {
        throw std::runtime_error("Обратная матрица существует только для квадратных матриц.");
    }

    // Создаем расширенную матрицу, добавляя единичную матрицу справа от исходной
    Matrix extended(rows, cols * 2);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            extended.data[i][j] = data[i][j];
            extended.data[i][j + cols] = (i == j) ? 1.0 : 0.0;
        }
    }

    // Применяем метод Гаусса-Жордана
    for (int i = 0; i < rows; ++i) {
        // Нормализуем строку i
        double diag = extended.data[i][i];
        if (std::abs(diag) < 1e-10) {
            throw std::runtime_error("Матрица вырождена и не имеет обратной.");
        }
        for (int j = 0; j < 2 * cols; ++j) {
            extended.data[i][j] /= diag;
        }

        // Обнуляем элементы в столбце i всех остальных строк
        for (int k = 0; k < rows; ++k) {
            if (k == i) continue;
            double factor = extended.data[k][i];
            for (int j = 0; j < 2 * cols; ++j) {
                extended.data[k][j] -= factor * extended.data[i][j];
            }
        }
    }

    // Извлекаем обратную матрицу из расширенной
    Matrix inverse(rows, cols);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            inverse.data[i][j] = extended.data[i][j + cols];
        }
    }

    return inverse;
}

void Matrix::display() const {

    for (const auto& row : data) {
        for (double val : row) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }    
}
