//{{ �������:
// Ctrl + K, Ctrl + C/U - ���������������� / �����������������
// Ctrl + K, Ctrl + F - �������������� ����
// Ctrl + M, Ctrl + H - ������ ������� ����
//}}

#include <iostream>

#include "Matrix.h"

using namespace std;

int main() {

	setlocale(LC_ALL, "Russian"); // ��������� ��������� ���������� ���������	

	int answer = 0;	// ������ ��������� �������� (�������)

	while (true) {

		cout << "������� ����� ������� (�� 1 �� 5): ";

		if (!(cin >> answer) || answer < 1 || answer > 5) {
			cout << "������: ������� ����� ����� �� 1 �� 5." << endl;
			cin.clear(); // ������� ���� ������ �����
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ������� ����� �����
			continue; // ��������� � ��������� �������� �����
		}

		switch (answer) {
		case 1: {
			cout << "������� ������� 1." << endl;

			Matrix A(5, 5); // �������� ������� �������� 5x5

			// ���������� ��������� ������ 3x3
			Matrix identityBlock(3, 3);
			for (int i = 0; i < 3; ++i) {
				identityBlock.data[i][i] = 1;
			}
			A.setBlock(0, 0, identityBlock);

			// ���������� ��������� ����� ������� �������
			A.data[0][3] = 2; A.data[0][4] = 8;
			A.data[1][3] = -5; A.data[1][4] = 4;
			A.data[2][3] = -6; A.data[2][4] = 4;
			A.data[3][0] = -5; A.data[3][1] = -7; A.data[3][2] = 1; A.data[3][3] = 6; A.data[3][4] = -9;
			A.data[4][0] = 4; A.data[4][1] = -6; A.data[4][2] = -3; A.data[4][3] = 8; A.data[4][4] = 8;

			// ����� �������� �������
			cout << "�������� ������� A:" << endl;
			A.display();

			// ���������� �������� �������
			Matrix A_inv = A.getInverse();

			// ����� �������� �������
			cout << "�������� ������� A_inv:" << endl;
			A_inv.display();

			return 0;
		}
		case 2:
			cout << "������� ������� 2." << endl;
			return 0;
		case 3:
			cout << "������� ������� 3." << endl;
			return 0;
		case 4:
			cout << "������� ������� 4." << endl;
			return 0;
		case 5:
			cout << "������� ������� 5." << endl;
			return 0;
		default:
			cout << "������� ��� ������� " << answer << " ���!" << endl;
		}
	}
	return 0;
}
