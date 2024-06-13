#pragma once

const int N = 5; // ����������� ������� ���������
const double EPSILON = 0.000001; // �������� ��� �������� ���������� �������
const int MAX_ITERATIONS = 100; // ������������ ���������� �������� ��� �������

// ���������� �������
void printArray(double arr[N]);
void simpleIterationsMethod(double a[N][N], double b[N], double x[N]);
void seidelMethod(double a[N][N], double b[N], double x[N]);