//---------------------------------------------------------
// автор коду Едуард Любарець Максимович РЕ-41
// виконано в рамках навчальної дисципліни РТФ
// Двовимірні динамічні масиви, операції над матрицями
// крайній реліз 16.06.2025
//---------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include "Matrices_Operations.h"

int main() {
	//оголошення змінних
	int method;
	int rowCount;
	int columnCount;
	int** mainMatrix;

	//ініціалізація методу
	printf("            ***|Enter 1 - 3 to choose calculation type|***             \n");
	printf("* 1 - matrix min. value\n* 2 - matrix transpose\n* 3 - matrix multiplying\n");
	scanf_s("%d", &method);

	if (method < 1 || method > 3) {
		printf("undefined method");
		return 1;
	}

	//ініціалізація параметрів основної матриці
	printf("Enter number of matrix rows\n");
	scanf_s("%d", &rowCount);
	printf("Enter number of matrix columns\n");
	scanf_s("%d", &columnCount);

	//ініціалізація та виведення основної матриці
	mainMatrix = memorySet(rowCount, columnCount);
	initMatrix(rowCount, columnCount, mainMatrix);
	printf("main matrix:\n");
	printMatrix(rowCount, columnCount, mainMatrix);

	//пошук мінімального значення
	if (method == 1) {
		int minValue = matrixMinValue(rowCount, columnCount, mainMatrix);
		printf("min. value = %d\n", minValue);
	}

	//транспонування
	if (method == 2) {
		printf("transponded matrix:\n");
		int** transponedMatrix = matrixTranspose(rowCount, columnCount, mainMatrix);
		printMatrix(columnCount, rowCount, transponedMatrix);
		memoryErase(transponedMatrix, columnCount);
	}

	//множення
	if (method == 3) {
		int rowCount2;
		int columnCount2;

		//ініціалізація параметрів допоміжної матриці
		printf("Enter number of second matrix rows\n");
		scanf_s("%d", &rowCount2);
		printf("Enter number of second matrix columns\n");
		scanf_s("%d", &columnCount2);

		//перевірка суміжності матриць
		if (columnCount != rowCount2) {
			printf("Can't multiply matrices, they are not adjacent");
			return (1);
		}

		//ініціалізація та виведення допоміжної матриці
		int** matrix2 = memorySet(rowCount2, columnCount2);
		initMatrix(rowCount2, columnCount2, matrix2);
		printf("second matrix:\n");
		printMatrix(rowCount2, columnCount2, matrix2);

		//обчислення та виведення результуючої матриці
		int** multipliedMatrix = multiplyMatrices(mainMatrix, matrix2, rowCount, columnCount, rowCount2, columnCount2);
		printf("multiplied matrix:\n");
		printMatrix(columnCount2, rowCount, multipliedMatrix);

		//очищення пам'яті відведеної для допоміжної матриці
		memoryErase(matrix2, rowCount2);
		memoryErase(multipliedMatrix, columnCount2);
	}

	//очищення пам'яті відведеної для основної матриці
	memoryErase(mainMatrix, rowCount);
	return 0;
}
