#include "Matrix.h"
#include <iostream>
#include <cmath>

// Функция для вывода одномерного массива на экран
void printArray(double arr[N]) {
    for (int i = 0; i < N; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

// Метод простых итераций для решения СЛАУ
void simpleIterationsMethod(double a[N][N], double b[N], double x[N]) {
    double temp[N]; // Временный массив для хранения текущих значений неизвестных
    bool done = false; // Флаг завершения вычислений
    int iterations = 0; // Счетчик итераций

    // Основной цикл метода простых итераций
    while (!done && iterations < MAX_ITERATIONS) {
        done = true;
        for (int i = 0; i < N; ++i) {
            temp[i] = b[i];
            for (int j = 0; j < N; ++j) {
                if (i != j) {
                    temp[i] -= a[i][j] * x[j];
                }
            }
            temp[i] /= a[i][i];
            if (std::abs(temp[i] - x[i]) > EPSILON) {
                done = false;
            }
            x[i] = temp[i];
        }
        // Вывод текущей итерации на экран
        std::cout << "Итерация " << iterations + 1 << ": ";
        printArray(x);
        iterations++;
    }
}

// Метод Зейделя для решения СЛАУ
void seidelMethod(double a[N][N], double b[N], double x[N]) {
    double temp; // Временная переменная для хранения текущего значения неизвестной
    bool done = false; // Флаг завершения вычислений
    int iterations = 0; // Счетчик итераций

    // Основной цикл метода Зейделя
    while (!done && iterations < MAX_ITERATIONS) {
        done = true;
        for (int i = 0; i < N; ++i) {
            temp = b[i];
            for (int j = 0; j < i; ++j) {
                temp -= a[i][j] * x[j];
            }
            for (int j = i + 1; j < N; ++j) {
                temp -= a[i][j] * x[j];
            }
            temp /= a[i][i];
            if (std::abs(temp - x[i]) > EPSILON) {
                done = false;
            }
            x[i] = temp;
        }
        // Вывод текущей итерации на экран
        std::cout << "Итерация " << iterations + 1 << ": ";
        printArray(x);
        iterations++;
    }
}
