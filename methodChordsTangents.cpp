#include "methodChordsTangents.h"
#include <cmath>

// Реализация функции f(x).
double f(double x) {
    return 2 * std::pow(x, 3) + 4 * std::pow(x, 2) + x + 3;
}

// Реализация производной функции f(x).
double df(double x) {
    return 6 * std::pow(x, 2) + 8 * x + 1;
}

// Реализация метода хорд.
double chord(double x0, double x1, double eps) {
    double x2;
    do {
        x2 = x1 - f(x1) * (x1 - x0) / (f(x1) - f(x0));
        x0 = x1;
        x1 = x2;
    } while (std::abs(f(x2)) > eps);
    return x2;
}

// Реализация метода касательных (метод Ньютона).
double tangent(double x0, double eps) {
    double x1;
    do {
        x1 = x0 - f(x0) / df(x0);
        x0 = x1;
    } while (std::abs(f(x1)) > eps);
    return x1;
}