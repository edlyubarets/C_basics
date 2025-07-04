﻿//---------------------------------------------------------
// автор коду Едуард Любарець Максимович РЕ-41
// виконано в рамках навчальної дисципліни РТФ
// Мультиметодологічний розрахунок інтегралів 
// крайній реліз 16.06.2025
//---------------------------------------------------------
#pragma once
#include<stdlib.h>  //директива препроцесора
#include<stdio.h>
#include<math.h>

//функція інтегралу
//оголошення прототипу функції та реалізація
//даний вираз використовується багато разів у вихідному коді
double myFunction(double x); //прототип або сигнатура функції

//перший математичний метод розрахунку інтеграла(лівих прямокутників)
//----------- опис функції-----------
//функція повертає результат розрахунку інтегралу
//тип даних: double
//-----------опис параметрів----------
//firstArgument - ліва межа інтегрування
//lastArgument - права межа інтегрування
//precision - кількість ітерацій пошуку значення
double method_A(double firstArgument, double lastArgument, int precision);

//другий математичний метод розрахунку інтеграла(правих прямокутників)
//----------- опис функції-----------
//функція повертає результат розрахунку інтегралу
//тип даних: double
//-----------опис параметрів----------
//firstArgument - ліва межа інтегрування
//lastArgument - права межа інтегрування
//precision - кількість ітерацій пошуку значення
double method_B(double firstArgument, double lastArgument, int precision);

//другий математичний метод розрахунку інтеграла(трапецій)
//----------- опис функції-----------
//функція повертає результат розрахунку інтегралу
//тип даних: double
//-----------опис параметрів----------
//firstArgument - ліва межа інтегрування
//lastArgument - права межа інтегрування
//precision - кількість ітерацій пошуку значення
double method_C(double firstArgument, double lastArgument, int precision);

//другий математичний метод розрахунку інтеграла(сімпсона)
//----------- опис функції-----------
//функція повертає результат розрахунку інтегралу
//тип даних: double
//-----------опис параметрів----------
//firstArgument - ліва межа інтегрування
//lastArgument - права межа інтегрування
//precision - кількість ітерацій пошуку значення
double method_D(double firstArgument, double lastArgument, int precision);

//обчислення результату інтегрування заданим методом
//----------- опис функції-----------
//функція повертає результат розрахунку інтегралу за обраним методом
//тип даних: double
//-----------опис параметрів----------
//methodNumber - номер методу пошуку значення інтегралу
//firstArgument - ліва межа інтегрування
//lastArgument - права межа інтегрування
//precision - кількість ітерацій пошуку значення
double calculateByMethod(int methodNumber, float firstArgument, float lastArgument, int precision);
