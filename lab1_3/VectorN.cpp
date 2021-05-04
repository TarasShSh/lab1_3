/*
У  всіх  завданнях,  крім  вказаних  в  завданні  операцій,  обов’язково мають бути реалізовані наступні методи:
-метод ініціалізації Init();
-метод введення з клавіатури Read();
-метод виведення на екран Displау();
-метод перетворення до літерного рядку toString()
*/

#include "VectorN.h"
#include <iostream>
#include <string>
#include <sstream>
#include < cmath >

using namespace std;
void VectorN::Display() const
{
	cout << toString();
	cout << endl;
}

void VectorN::Init(int N, int  el, int i)
{
	setN(N);
	a.reserve(N);
	setA(el, i);
}

void VectorN::Read()
{
	int N, el;
	// Створення вектора
	cout << "Розмірність вектора: "; cin >> N;
	for (int i = 0; i < N; i++)
	{
		cout << "Елемент №" << i+1 << " = "; cin >> el;
		Init(N, el, i);
	}
	Display();
	int option;
	cout << "   Дії над вектором"			<< endl;
	cout << "(1)Множення на скаляр"			<< endl;
	cout << "(2)Обчислення довжини вектора" << endl;
	cout << "(3)Дії над векторами"				<< endl;
	cout << "Оберіть дію: ";			cin >> option;
	switch (option)
	{
	case 1:
		cout << "Введіть скаляр: "; cin >> k;
		mScalar(k);
		break;
	case 2:
		lVector();
		break;
	case 3:
		break;
	case 4:
		break;
	default:
		break;
	}
}

string VectorN::toString() const
{
	stringstream sout; // створили об'єкт "літерний потік"
	// направляємо в літерний потік
	string vect;
	for (int i = 0; i < N; i++)
	{
		ostringstream strg;
		strg << a[i];
		vect += strg.str() + "; ";
	}
	sout << "Вектор = { " << vect << "}" << endl; 
	cout << " N = " << N << endl;
	cout << "Перший = " << a[0] << endl;
	// виведення даних про об'єкт
	return sout.str();	// str() перетворює літерний потік до літерного рядка
}

/*
	Обов’язково мають бути реалізовані:
- множення на скаляр,			k*a = (k*a[0], k*a[1])
- обчислення довжини вектора,	|a| = sqrt(a[0]^2 +a[1]^2..+a[n]^2)
- порівняння векторів,			a[0] == b[0] .. a[n] == b[n]
- порівняння довжин векторів.	|a| == |b|
*/

void VectorN::mScalar(int k)
{
	for (int i = 0; i < N; i++)
	{
		a.at(i) = a[i] * k;
		cout << a[i] << endl;
	}
	Display();
}
int VectorN::lVector()
{
	int length = 0;
	for (int i = 0; i < N; i++)
	{
		length += a[i] * a[i];
	}
	length = abs(sqrt(length));
	return length;
}
bool VectorN::Compare(VectorN name)
{
	if (getN() == name.getN())
	{
		bool tf;
		int tfr = 0;
		for (int i = 0; i < N; i++)
		{
			tf = a[i] == name.a[i];
			if (tf == false)
			{
				tfr += 1;
			}
		}
		if (tfr == 0)
		{
			cout << "Вектори однакові.";
			return true;
		}
		else if (tfr > 0)
		{
			cout << "Вектори не однакові.";
			return false;
		}
	}
	else
	{
		cout << "Розмірність векторів не однакова!";
		return false;
	}
}
bool VectorN::lCompare(VectorN name) 
{
	bool lc = lVector() == name.lVector();
	if (lc)
	{
		cout << "Довжини векторів рівні." << endl;
		return true;
	}
	else if (!lc)
	{
		cout << "Довжини векторів не рівні." << endl;
		return false;
	}
}

