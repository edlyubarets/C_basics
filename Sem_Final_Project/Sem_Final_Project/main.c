//---------------------------------------------------------
// автор коду Едуард Любарець Максимович РЕ-41
// виконано в рамках навчальної дисципліни РТФ
// Підсумкова робота: математичні операції, двовимірні динамічні масиви, робота з файлами
// крайній реліз 16.06.2025
//---------------------------------------------------------

#include"Sem_Final_Project.h"
#include<stdlib.h>
#include<stdio.h>
#include<math.h>

int main() {
	int task;
	double t1_a;
	unsigned int t1_N;
	unsigned int t2_N;

	printf("Enter task(1, 2 or 3)\n");
	scanf_s("%d", &task);
	fflush(stdin);
	if (task != 1 && task != 2 && task != 3) {
		printf("Undefined task\n");
		return 1;
	}

	if (task == 1) {
		printf("Enter argument value\n");
		scanf_s("%lf", &t1_a);
		printf("Enter sum coeficient\n");
		scanf_s("%u", &t1_N);

		firstTaskFunction(t1_a, t1_N);
	}

	if (task == 2) {
		printf("Enter square matrix dimension\n");
		scanf_s("%d", &t2_N);
		secondTaskFunction(t2_N);
	}

	if (task == 3) {
		char fileName[100];
		char symbol;
		printf("Enter file name: ");
		scanf_s("%s", &fileName, 100);
		printf("Enter symbol: ");
		scanf_s("%c", &symbol, 1);
		scanf_s("%c", &symbol, 1);

		thirdTaskFunction(fileName, symbol);		//  c:\temp\test.txt
	}
	return 0;
}