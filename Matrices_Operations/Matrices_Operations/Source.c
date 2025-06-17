#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX_RANDOM_MATRIX_VALUE 20;

//виділення пам'яті під массив
int** memorySet(int rowCount, int columnCount) {
	int** matrix = (int**)calloc(rowCount, sizeof(int*));

	if (matrix == NULL) {			//перевірка виділення пам'яті 1
		printf("Memory has not been allocated");
		exit(0);
	}

	for (int i = 0; i < rowCount; i++) {
		matrix[i] = (int*)calloc(columnCount, sizeof(int));

		if (matrix[i] == NULL) {	//перевірка виділення пам'яті 2
			printf("Memory has not been allocated");
			exit(0);
		}
	}

	return matrix;
}

//стирання виділеної пам'яті
void memoryErase(int** sourceArray, int rowCount) {

	for (int i = 0; i < rowCount; i++) {
		free(sourceArray[i]);
	}

	free(sourceArray);
}

//виведення матриці
void printMatrix(int rowCount, int columnCount, int** sourceArray) {
	for (int i = 0; i < rowCount; i++) {
		for (int j = 0; j < columnCount; j++) {
			int r = sourceArray[i][j];		//впорядкування символів
			if (r <= 9) {
				printf(" %d ", r);
			}
			else
			{
				printf("%d ", r);
			}
		}
		printf("\n");
	}
}

//ініціалізація елементів матриці
void initMatrix(int rowCount, int columnCount, int** sourceArray) {
	for (int i = 0; i < rowCount; i++) {
		for (int j = 0; j < columnCount; j++) {		//ініц. елементів рандомними значеннями
			sourceArray[i][j] = rand() % MAX_RANDOM_MATRIX_VALUE + 1;
		}
	}
}

//пошук найменшого елементу матриці
int matrixMinValue(int rowCount, int columnCount, int** sourceArray) {
	int minValue = 2147483647;              //оголошення та ініціалізація допоміжної змінної
	for (int i = 0; i < rowCount; i++) {
		for (int j = 0; j < columnCount; j++) {
			if (sourceArray[i][j] < minValue) {		//пошук значення методом порівняння
				minValue = sourceArray[i][j];
			}
		}
	}
	return minValue;
}

//транспонування матриці
int** matrixTranspose(int rowCount, int columnCount, int** sourceArray) {
	int** result = memorySet(columnCount, rowCount);	//виділення пам'яті для результуючої матриці

	for (int i = 0; i < columnCount; i++) {
		for (int j = 0; j < rowCount; j++) {
			result[i][j] = sourceArray[j][i];
		}
	}
	return result;
}

//множення матриць
int** multiplyMatrices(int** firstMatrix, int** secondMatrix, int rowFirst, int colFirst, int rowSecond, int colSecond) {
	int** resultM = memorySet(colSecond, rowFirst);		//виділення пам'яті для результуючої матриці
	for (int i = 0; i < rowFirst; i++) {
		for (int j = 0; j < colSecond; j++) {
			for (int k = 0; k < colFirst; k++) {
				resultM[i][j] += firstMatrix[i][k] * secondMatrix[k][j];	//розрахунок елементу
			}
		}
	}

	return resultM;
}
