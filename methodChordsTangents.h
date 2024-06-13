#pragma once

double f(double x); // Функция f(x) для которой ищем корень.
double df(double x); // Производная функции f(x).
double chord(double x0, double x1, double eps); // Метод хорд для нахождения приближенного значения корня.
double tangent(double x0, double eps); // Метод касательных (метод Ньютона) для уточнения значения корня.