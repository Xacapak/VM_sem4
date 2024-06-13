#include "MatrixInverse.h"
#include <iostream>

// Функция для вычисления определителя матрицы
// mat: Входная матрица, для которой необходимо вычислить определитель
// n: Размерность матрицы
static double Determinant(double mat[NI][NI], int n) {
    double det = 0;
    double submat[NI][NI];

    if (n == 2)
        return ((mat[0][0] * mat[1][1]) - (mat[1][0] * mat[0][1]));

    for (int x = 0; x < n; x++) {
        int subi = 0;
        for (int i = 1; i < n; i++) {
            int subj = 0;
            for (int j = 0; j < n; j++) {
                if (j == x)
                    continue;
                submat[subi][subj] = mat[i][j];
                subj++;
            }
            subi++;
        }
        det += (x % 2 == 0 ? 1 : -1) * mat[0][x] * Determinant(submat, n - 1);
    }
    return det;
}

// Функция для нахождения обратной матрицы
// mat: Входная матрица, для которой необходимо найти обратную матрицу
// inv: Матрица, в которую будет записан результат
void InverseMatrix(double mat[NI][NI], double inv[NI][NI]) {
    double det = Determinant(mat, NI);
    if (det == 0) {
        std::cerr << "Обратной матрицы не существует." << std::endl;
        return;
    }

    double temp[NI][NI];

    for (int i = 0; i < NI; i++) {
        for (int j = 0; j < NI; j++) {
            // Получаем минор M(i, j)
            int p = 0, q = 0;

            for (int row = 0; row < NI; row++) {
                for (int col = 0; col < NI; col++) {
                    if (row != i && col != j) {
                        temp[p][q++] = mat[row][col];
                        if (q == NI - 1) {
                            q = 0;
                            p++;
                        }
                    }
                }
            }

            double sign = (i + j) % 2 == 0 ? 1 : -1;
            inv[j][i] = (sign * Determinant(temp, NI - 1)) / det;
        }
    }
}

// Функция для вывода матрицы
// mat: Матрица для вывода
void DisplayMatrix(double mat[NI][NI]) {
    for (int i = 0; i < NI; i++) {
        for (int j = 0; j < NI; j++)
            std::cout << mat[i][j] << "\t";
        std::cout << std::endl;
    }
}