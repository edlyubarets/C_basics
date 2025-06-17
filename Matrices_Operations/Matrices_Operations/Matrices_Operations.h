//---------------------------------------------------------
// автор коду Едуард Любарець Максимович РЕ-41
// виконано в рамках навчальної дисципліни РТФ
// Двовимірні динамічні масиви, операції над матрицями
// крайній реліз 16.06.2025
//---------------------------------------------------------

#pragma once

//виділення пам'яті під массив
int** memorySet(int rowCount, int columnCount);
//стирання виділеної пам'яті
void memoryErase(int** sourceArray, int rowCount);
//виведення матриці
void printMatrix(int rowCount, int columnCount, int** sourceArray);
//ініціалізація елементів матриці
void initMatrix(int rowCount, int columnCount, int** sourceArray);
//пошук найменшого елементу матриці
int matrixMinValue(int rowCount, int columnCount, int** sourceArray);
//транспонування матриці
int** matrixTranspose(int rowCount, int columnCount, int** sourceArray);
//множення матриць
int** multiplyMatrices(int** firstMatrix, int** secondMatrix, int rowFirst, int colFirst, int rowSecond, int colSecond);