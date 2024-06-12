//{{ Памятка:
// Ctrl + K, Ctrl + C/U - закомментировать / раскомментировать
// Ctrl + K, Ctrl + F - форматирование кода
// Ctrl + M, Ctrl + H - Скрыть строчки кода
//}}

#include <iostream>

#include "Matrix.h"

using namespace std;

int main() {

	setlocale(LC_ALL, "Russian"); // Позволяет корректно отображать кириллицу	

	int answer = 0;	// Хранит выбранное значение (задание)

	while (true) {

		cout << "Введите номер задания (от 1 до 5): ";

		if (!(cin >> answer) || answer < 1 || answer > 5) {
			cout << "Ошибка: введите целое число от 1 до 5." << endl;
			cin.clear(); // Очищаем флаг ошибки ввода
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Очищаем буфер ввода
			continue; // Переходим к следующей итерации цикла
		}

		switch (answer) {
		case 1: {
			cout << "Выбрано задание 1." << endl;

			Matrix A(5, 5); // Исходная матрица размером 5x5

			// Заполнение единичным блоком 3x3
			Matrix identityBlock(3, 3);
			for (int i = 0; i < 3; ++i) {
				identityBlock.data[i][i] = 1;
			}
			A.setBlock(0, 0, identityBlock);

			// Заполнение остальной части матрицы данными
			A.data[0][3] = 2; A.data[0][4] = 8;
			A.data[1][3] = -5; A.data[1][4] = 4;
			A.data[2][3] = -6; A.data[2][4] = 4;
			A.data[3][0] = -5; A.data[3][1] = -7; A.data[3][2] = 1; A.data[3][3] = 6; A.data[3][4] = -9;
			A.data[4][0] = 4; A.data[4][1] = -6; A.data[4][2] = -3; A.data[4][3] = 8; A.data[4][4] = 8;

			// Вывод исходной матрицы
			cout << "Исходная матрица A:" << endl;
			A.display();

			// Нахождение обратной матрицы
			Matrix A_inv = A.getInverse();

			// Вывод обратной матрицы
			cout << "Обратная матрица A_inv:" << endl;
			A_inv.display();

			return 0;
		}
		case 2:
			cout << "Выбрано задание 2." << endl;
			return 0;
		case 3:
			cout << "Выбрано задание 3." << endl;
			return 0;
		case 4:
			cout << "Выбрано задание 4." << endl;
			return 0;
		case 5:
			cout << "Выбрано задание 5." << endl;
			return 0;
		default:
			cout << "Задания под номером " << answer << " нет!" << endl;
		}
	}
	return 0;
}
