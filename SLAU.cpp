#include "SLAU.h"
#include <cmath>

// Функция для обмена двух строк матрицы
void swapRows(double matrix[MAXN][MAXN + 1], int row1, int row2, int colCount) {
    for (int i = 0; i <= colCount; ++i) {
        double temp = matrix[row1][i]; // Временная переменная для хранения значения элемента
        matrix[row1][i] = matrix[row2][i]; // Перемещение элемента из второй строки в первую
        matrix[row2][i] = temp; // Перемещение элемента из временной переменной во вторую строку
    }
}

// Функция для решения СЛАУ методом Жордана-Гаусса
void jordanGauss(double matrix[MAXN][MAXN + 1], double x[MAXN], int n) {
    const double EPS = 0.00001; // Пороговое значение для сравнения с нулем

    for (int i = 0; i < n; ++i) {
        // Поиск максимального элемента в текущем столбце
        int maxRow = i; // Индекс строки с максимальным элементом
        for (int k = i + 1; k < n; ++k) {
            if (abs(matrix[k][i]) > abs(matrix[maxRow][i])) {
                maxRow = k; // Обновление индекса строки с максимальным элементом
            }
        }

        // Вызов функции обмена строк
        swapRows(matrix, i, maxRow, n);

        // Нормализация строки
        for (int k = n; k >= i; --k) {
            matrix[i][k] /= matrix[i][i]; // Деление элементов строки на ведущий элемент
        }

        // Обнуление элементов в столбце ниже и выше текущего
        for (int k = 0; k < n; ++k) {
            if (k != i) {
                double coef = matrix[k][i]; // Коэффициент для обнуления элементов
                for (int j = n; j >= i; --j) {
                    matrix[k][j] -= coef * matrix[i][j]; // Обнуление элементов
                }
            }
        }
    }

    // Вычисление решений системы
    for (int i = 0; i < n; ++i) {
        x[i] = matrix[i][n]; // Присваивание решения
        if (abs(x[i]) < EPS) x[i] = 0; // Округление до нуля, если значение меньше порога
    }
}