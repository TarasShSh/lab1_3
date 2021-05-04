// lab1_3.cpp
// Шевченко Тарас
// Лабораторна робота № 1.3
// Об’єкти –параметри методів (дії над кількома об’єктами)
// Варіант 23
#include <iostream>
#include<iomanip>
#include<time.h>
#include <locale>
#include "windows.h"
#include "VectorN.h"

using namespace std;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    VectorN FirstVector;
    FirstVector.Read();
    VectorN SecondVector;
    SecondVector.Read();
    cout << endl;
    cout << "(1)Порівняння векторів"        << endl;
    cout << "(2)Порівняння довжин векторів" << endl;
    cout << "Оберіть дію: ";
    int option;
    cin >> option;
    if (option == 1)
    {
        SecondVector.Compare(FirstVector);
    }
    else if (option == 2)
    {
        SecondVector.lCompare(FirstVector);
    }
}
