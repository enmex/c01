﻿// c01.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "DynamicArray.h"
#include <locale.h>
using namespace std;

int main()
{
    setlocale(LC_ALL, "Rus");
    cout << "Введите первый массив\n";
    DynamicArray test;
    cin >> test;
    cout << test;
    cout << "\nВведите второй массив\n";
    DynamicArray test1;
    cin >> test1;
    cout << test1;

    cout << "Результат сложения: " << test + test1 << endl;
}
