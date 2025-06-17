//---------------------------------------------------------
// автор коду Едуард Любарець Максимович РЕ-41
// виконано в рамках навчальної дисципліни РТФ
// Робота з файлами
// крайній реліз 16.06.2025
//---------------------------------------------------------

#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#include "Files_Operations.h"
#define dataFile "c:\\temp\\test.txt"
#define textFile "c:\\temp\\result.txt"
#define binaryFile "c:\\temp\\resultB.bin"

int main() {
	double x1;
	double x2;
	double delta;
	char dataFileCatalog[50] = dataFile;
	char textFileCatalog[50] = textFile;
	char binaryFileCatalog[50] = binaryFile;

	readTaskData(dataFileCatalog, &x1, &x2, &delta);

	printResultConsole(x1, x2, delta);

	createTextFile(x1, x2, delta, textFileCatalog);

	createBinaryFile(x1, x2, delta, binaryFileCatalog);

	readPrintBinaryData(binaryFileCatalog);

	return 0;
}