#include"Sem_Final_Project.h"
#include<stdlib.h>
#include<stdio.h>
#include<math.h>

void firstTaskFunction(double a, unsigned int N) {
	double result = 0;
	for (int k = 0; k < (int)N; k++) {
		double v = 2 * k + 1;
		int factorialValue = 1;
		double poweredValue = 1;

		//обчислення степеню
		for (int p = 0; p < v; p++) {
			poweredValue = poweredValue * a;
		}
		//обчислення факторіалу
		for (int f = v; f > 1; f--) {
			factorialValue = factorialValue * f;
		}

		double semiResult = poweredValue / factorialValue;
		result = result + semiResult;
	}
	printf("result: %lf\n", result);
}



void secondTaskFunction(int N) {
	//виділення пам'яті для основної матриці
	int** matrix_A = (int**)calloc(N, sizeof(int*));
	if (matrix_A == NULL) {
		printf("Memory allocation error");
		exit(0);
	}
	for (int i = 0; i < N; i++) {
		matrix_A[i] = (int*)calloc(N, sizeof(int));
		if (matrix_A[i] == NULL) {
			printf("Memory allocation error");
			exit(0);
		}
	}
	//виділення пам'яті для допоміжного массиву
	int extraArraySize = N * N;
	int* extraArray = (int*)calloc(extraArraySize, sizeof(int));
	if (extraArray == NULL) {
		printf("Memory allocation error");
		exit(0);
	}
	//виділення пам'яті для відсортованої матриці
	int** matrix_B = (int**)calloc(N, sizeof(int*));
	if (matrix_B == NULL) {
		printf("Memory allocation error");
		exit(0);
	}
	for (int i = 0; i < N; i++) {
		matrix_B[i] = (int*)calloc(N, sizeof(int));
		if (matrix_B[i] == NULL) {
			printf("Memory allocation error");
			exit(0);
		}
	}
	//ініціалізація елементів основної матриці
	int value_max = 5 + rand() % (9 - 5 + 1);
	int value_min = value_max * (-1);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			matrix_A[i][j] = value_min + rand() % (value_max - value_min + 1);
		}
	}
	//вивід основної матриці
	printf("\n");
	printf("matrix A\n");
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int e = matrix_A[i][j];
			if (e > 9 || e < 0) {
				printf("%d ", e);
			}
			else {
				printf(" %d ", e);
			}
		}
		printf("\n");
	}


	//ініціалізація елементів допоміжного массиву
	int extra_N = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			extraArray[extra_N] = matrix_A[i][j];
			extra_N++;
		}
	}
	extra_N = 0;
	//сортування методом бульбашки
	for (int i = 0; i < extraArraySize - 1; i++) {
		for (int j = 0; j < extraArraySize - 1; j++) {
			if (extraArray[j] > extraArray[j + 1]) {
				int temp = extraArray[j];
				extraArray[j] = extraArray[j + 1];
				extraArray[j + 1] = temp;
			}
		}
	}
	//ініціалізація елементів відсортованої матриці
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			matrix_B[i][j] = extraArray[extra_N];
			extra_N++;
		}
	}
	//вивід відсортованої матриці
	printf("\n");
	printf("matrix B (sorted)\n");
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int e = matrix_B[i][j];
			if (e > 9 || e < 0) {
				printf("%d ", e);
			}
			else {
				printf(" %d ", e);
			}
		}
		printf("\n");
	}
	//очищення пам'яті основної матриці
	for (int i = 0; i < N; i++) {
		free(matrix_A[i]);
	}
	free(matrix_A);
	//очищення пам'яті відсортованої матриці
	for (int i = 0; i < N; i++) {
		free(matrix_B[i]);
	}
	free(matrix_B);
	//очищення па'яті допоміжного массиву
	free(extraArray);
}

void thirdTaskFunction(char* fileName, char* s) {
	//відкриття файлу в режимі читання
	FILE* file = fopen(fileName, "r");
	if (file == NULL) {
		printf("File opening error\n");
		exit(0);
	}
	//підрахунок кількості символів
	char symbol;
	unsigned int counter = 0;
	while ((symbol = fgetc(file)) != EOF) {
		if (symbol == s) {
			counter++;
		}
	}
	printf("number of current symbol in file: %u\n", counter);
	fclose(file);
}