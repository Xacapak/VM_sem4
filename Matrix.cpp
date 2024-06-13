#include "Matrix.h"
#include <iostream>
#include <cmath>

// ������� ��� ������ ����������� ������� �� �����
void printArray(double arr[N]) {
    for (int i = 0; i < N; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

// ����� ������� �������� ��� ������� ����
void simpleIterationsMethod(double a[N][N], double b[N], double x[N]) {
    double temp[N]; // ��������� ������ ��� �������� ������� �������� �����������
    bool done = false; // ���� ���������� ����������
    int iterations = 0; // ������� ��������

    // �������� ���� ������ ������� ��������
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
        // ����� ������� �������� �� �����
        std::cout << "�������� " << iterations + 1 << ": ";
        printArray(x);
        iterations++;
    }
}

// ����� ������� ��� ������� ����
void seidelMethod(double a[N][N], double b[N], double x[N]) {
    double temp; // ��������� ���������� ��� �������� �������� �������� �����������
    bool done = false; // ���� ���������� ����������
    int iterations = 0; // ������� ��������

    // �������� ���� ������ �������
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
        // ����� ������� �������� �� �����
        std::cout << "�������� " << iterations + 1 << ": ";
        printArray(x);
        iterations++;
    }
}
