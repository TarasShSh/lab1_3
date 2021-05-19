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
    FirstVector.Display();
    int option;
    cout << "   Дії над вектором" << endl;
    cout << "(1)Множення на скаляр" << endl;
    cout << "(2)Обчислення довжини вектора" << endl;
    cout << "(3)Дії над векторами" << endl;
    cout << "Оберіть дію: "; cin >> option;
    switch (option)
    {
    case 1:
        int k;
        cout << "Введіть скаляр: "; cin >> k;
        mul(FirstVector, k).Display();
        break;
    case 2:
        FirstVector.len();
        break;
    case 3:
        break;
    default:
        break;
    }

    VectorN SecondVector;
    SecondVector.Read();
    cout << endl;
    cout << "(1)Порівняння векторів" << endl;
    cout << "(2)Порівняння довжин векторів" << endl;
    cout << "Оберіть дію: ";;
    cin >> option;
    if (option == 1)
    {
        if (E(FirstVector, SecondVector) && !NE(FirstVector, SecondVector))
        {
            cout << "Вектори однакові" << endl;
        } 
        else if (!E(FirstVector, SecondVector) && NE(FirstVector, SecondVector))
        {
            cout << "Вектори не однакові" << endl;
        }
    }
    else if (option == 2)
    {
       
        if (LE(FirstVector, SecondVector) && L(FirstVector, SecondVector))
        {
            cout << "Довжина першого вектора менша від другого" << endl;
        } 
        else if (GE(FirstVector, SecondVector) && G(FirstVector, SecondVector))
        {
            cout << "Довжина першого вектора більша від другого" << endl;
        }
        else
        {
            cout << "Довжина першого вектора дорівнює довжині другого" << endl;
        }
    }

FirstVector.Destroy();
SecondVector.Destroy();
}