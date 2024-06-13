#include "SLAU.h"
#include <cmath>

// ������� ��� ������ ���� ����� �������
void swapRows(double matrix[MAXN][MAXN + 1], int row1, int row2, int colCount) {
    for (int i = 0; i <= colCount; ++i) {
        double temp = matrix[row1][i]; // ��������� ���������� ��� �������� �������� ��������
        matrix[row1][i] = matrix[row2][i]; // ����������� �������� �� ������ ������ � ������
        matrix[row2][i] = temp; // ����������� �������� �� ��������� ���������� �� ������ ������
    }
}

// ������� ��� ������� ���� ������� �������-������
void jordanGauss(double matrix[MAXN][MAXN + 1], double x[MAXN], int n) {
    const double EPS = 0.00001; // ��������� �������� ��� ��������� � �����

    for (int i = 0; i < n; ++i) {
        // ����� ������������� �������� � ������� �������
        int maxRow = i; // ������ ������ � ������������ ���������
        for (int k = i + 1; k < n; ++k) {
            if (abs(matrix[k][i]) > abs(matrix[maxRow][i])) {
                maxRow = k; // ���������� ������� ������ � ������������ ���������
            }
        }

        // ����� ������� ������ �����
        swapRows(matrix, i, maxRow, n);

        // ������������ ������
        for (int k = n; k >= i; --k) {
            matrix[i][k] /= matrix[i][i]; // ������� ��������� ������ �� ������� �������
        }

        // ��������� ��������� � ������� ���� � ���� ��������
        for (int k = 0; k < n; ++k) {
            if (k != i) {
                double coef = matrix[k][i]; // ����������� ��� ��������� ���������
                for (int j = n; j >= i; --j) {
                    matrix[k][j] -= coef * matrix[i][j]; // ��������� ���������
                }
            }
        }
    }

    // ���������� ������� �������
    for (int i = 0; i < n; ++i) {
        x[i] = matrix[i][n]; // ������������ �������
        if (abs(x[i]) < EPS) x[i] = 0; // ���������� �� ����, ���� �������� ������ ������
    }
}