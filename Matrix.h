#pragma once

const int N = 5; // Размерность системы уравнений
const double EPSILON = 0.000001; // Точность для проверки сходимости методов
const int MAX_ITERATIONS = 100; // Максимальное количество итераций для методов

// Объявление функций
void printArray(double arr[N]);
void simpleIterationsMethod(double a[N][N], double b[N], double x[N]);
void seidelMethod(double a[N][N], double b[N], double x[N]);