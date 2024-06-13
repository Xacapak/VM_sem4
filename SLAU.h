#pragma once

// Максимальный размер матрицы
const int MAXN = 100;

// Объявление функции для решения СЛАУ методом Жордана-Гаусса
void jordanGauss(double matrix[MAXN][MAXN + 1], double x[MAXN], int n);