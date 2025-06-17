#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#include "Files_Operations.h"

void printDoubleAsString(double value, int maxWidth, char* specificator) {
	int length = snprintf(NULL, 0, specificator, value);
	int spacesCount = maxWidth - length;
	for (int i = 0; i < spacesCount; i++)
	{
		printf(" ");
	}
	printf(specificator, value);
}

void printMultiple(char s, int count, short nextLine) {
	for (int i = 0; i < count; i++) {
		printf("%c", s);
	}
	if (nextLine == 1) {
		printf("\n");
	}
}

void printIntertableRow() {
	printf("+----------+----------+----------+\n");
}

void printDots() {
	printf(". . . . . . . . . . . . . . . . .\n");
}

double myFunction(double x) {
	return pow(x / 100 - 5, 5) - pow(x / 50 + 10, 4) - pow(x / 25 - 15, 3) - pow(x, 2) - 10;
}

void readTaskData(char* fileName, double* x1, double* x2, double* delta) {
	FILE* dataFile = fopen(fileName, "r");
	if (dataFile == NULL) {
		printf("data file opening error");
		exit(1);
	}
	fscanf_s(dataFile, "%lf %lf %lf", x1, x2, delta);
	if (*delta <= 0) {
		printf("input data error");
		exit(1);
	}
	fclose(dataFile);
}

void printResultConsole(double x1, double x2, double delta) {
	printf("X1 = %.2lf, ", x1);
	printf("X2 = %.2lf, ", x2);
	printf("Delta = %.2lf\n", delta);
	printf("\n");
	printMultiple('*', 34, 1);
	printf("*     N    *     X    *   F(X)   *\n");
	printMultiple('*', 34, 1);
	int rowNumber = 1;
	int dotsCounter = 0;
	for (double i = x1; i < x2; i += delta) {
		printf("|");
		printDoubleAsString(rowNumber, 10, "%.0f");
		printf("|");
		printDoubleAsString(i, 10, "%.2f");
		printf("|");
		printDoubleAsString(myFunction(i), 10, "%.2f");
		printf("|\n");
		printIntertableRow();
		if (dotsCounter == 1) {
			printDots();
			dotsCounter = -1;
		}
		rowNumber++;
		dotsCounter++;
	}




}

void filePrintDoubleAsString(double value, int maxWidth, char* specificator, FILE* fileName) {
	int length = snprintf(NULL, 0, specificator, value);
	int spacesCount = maxWidth - length;
	for (int i = 0; i < spacesCount; i++)
	{
		fprintf(fileName, " ");
	}
	fprintf(fileName, specificator, value);
}

void filePrintMultiple(char s, int count, short nextLine, FILE* fileName) {
	for (int i = 0; i < count; i++) {
		fprintf(fileName, "%c", s);
	}
	if (nextLine == 1) {
		fprintf(fileName, "\n");
	}
}

void filePrintIntertableRow(FILE* fileName) {
	fprintf(fileName, "+----------+----------+----------+\n");
}

void filePrintDots(FILE* fileName) {
	fprintf(fileName, ". . . . . . . . . . . . . . . . .\n");
}

void createTextFile(double x1, double x2, double delta, char* fileCatalog) {
	FILE* textFile = fopen(fileCatalog, "w");
	if (textFile == NULL) {
		printf("text file opening error");
		exit(1);
	}

	fprintf(textFile, "X1 = %.2lf, ", x1);
	fprintf(textFile, "X2 = %.2lf, ", x2);
	fprintf(textFile, "Delta = %.2lf\n", delta);
	fprintf(textFile, "\n");
	filePrintMultiple('*', 34, 1, textFile);
	fprintf(textFile, "*     N    *     X    *   F(X)   *\n");
	filePrintMultiple('*', 34, 1, textFile);
	int rowNumber = 1;
	int dotsCounter = 0;
	for (double i = x1; i < x2; i += delta) {
		fprintf(textFile, "|");
		filePrintDoubleAsString(rowNumber, 10, "%.0f", textFile);
		fprintf(textFile, "|");
		filePrintDoubleAsString(i, 10, "%.2f", textFile);
		fprintf(textFile, "|");
		filePrintDoubleAsString(myFunction(i), 10, "%.2f", textFile);
		fprintf(textFile, "|\n");
		filePrintIntertableRow(textFile);
		if (dotsCounter == 1) {
			filePrintDots(textFile);
			dotsCounter = -1;
		}
		rowNumber++;
		dotsCounter++;
	}
	fclose(textFile);
}

void createBinaryFile(double x1, double x2, double delta, char* fileCatalog) {
	int pointsNumber = floor((x2 - x1) / delta);

	double* Arr = (double*)calloc(pointsNumber * 2, sizeof(double));
	if (Arr == NULL) {
		printf("Array memory allocation error");
		exit(1);
	}

	int counter = 0;
	for (double i = x1; i < x2; i += delta) {
		Arr[counter] = i;
		counter++;
		Arr[counter] = myFunction(i);
		counter++;
	}
	FILE* binaryFile = fopen(fileCatalog, "wb");
	if (binaryFile == NULL) {
		printf("binary file opening error");
		exit(1);
	}
	fwrite(&pointsNumber, sizeof(int), 1, binaryFile);
	fwrite(Arr, sizeof(double), pointsNumber * 2, binaryFile);

	if (fclose(binaryFile) != 0) {
		printf("Can't close binary file");
	}
	free(Arr);
}

void readPrintBinaryData(char* fileCatalog) {
	FILE* binaryDataFile = fopen(fileCatalog, "rb");
	if (binaryDataFile == NULL) {
		printf("binary data file opening error");
		exit(1);
	}

	int pointsNumber = 10;
	fread(&pointsNumber, sizeof(int), 1, binaryDataFile);

	double* dataArr = (double*)calloc(pointsNumber * 2, sizeof(double));

	if (dataArr == NULL) {
		printf("Array memory allocation error");
		exit(1);
	}

	fread(dataArr, sizeof(double), pointsNumber * 2, binaryDataFile);

	fclose(binaryDataFile);
	printf("\n\n");
	printf("*Binary data*\n");
	printf("points: %d\n", pointsNumber);

	for (int i = 0; i < pointsNumber * 2 - 1; i += 2) {
		printf("%.2lf %.2lf\n", dataArr[i], dataArr[i + 1]);
	}

	free(dataArr);
}