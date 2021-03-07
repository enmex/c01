// c01.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
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


    cout << "\nРезультат сложения: \n";
    DynamicArray multiply(test + test1);
    cout << multiply;

    multiply.resize(15);
    cout << "\nresize->15: " << multiply << endl;

    cout << "a < b :" << (test < test1) << endl;
    cout << "a > b :" << (test > test1) << endl;
    cout << "a <= b :" << (test <= test1) << endl;
    cout << "a >= b :" << (test >= test1) << endl;
    cout << "a = b :" << (test == test1) << endl << endl;

    multiply.reserve(10);
    cout << "Резервивание прошло успешно, размер " << multiply.capacity() << ", а размер массива " << multiply.getSize() << endl;
    multiply.resize(7);
    cout << "resize(7): " << multiply << endl;
    cout << "Изменение размера прошло успешно, размер " << multiply.capacity() << ", а размер массива " << multiply.getSize() << endl;

    DynamicArray a(0);
    int x;
    for (int i = 0; i < 15; i++) {
        cin >> x;
        a.pushBack(x);
        cout << a;
    }
    for (int i = 0; i < 15; i++) {
        cout << a;
        cout << a.popBack() << endl;
    }
}
