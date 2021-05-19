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

void VectorN::Destroy()
{
	delete[]a;
}

void VectorN::Init(int N)
{
	setN(N);
	a = new double[N];
	for (size_t i = 0; i < N; i++)
	{
		a[i] = 0;
	}
}

void VectorN::Read()
{
	int N;
	// Створення вектора
	cout << "Розмірність вектора: "; cin >> N;
	Init(N);

	for (int i = 0; i < N; i++)
	{
		cout << "Елемент №" << i + 1 << " = "; cin >> a[i];
	}
}
string VectorN::toString() const
{
	stringstream sout; // створили об'єкт "літерний потік"

	sout << "Вектор = { ";
	// направляємо в літерний потік
	for (int i = 0; i < N; i++)
	{
		sout << a[i] <<"; ";
	}
	sout << "}" << endl;
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


double VectorN::len() const
{
	double length = 0;
	for (int i = 0; i < N; i++)
	{
		length += a[i] * a[i];
	}
	length = sqrt(length);
	return length;
}
bool E(const VectorN& l, const VectorN& r)
{
	bool result = l.N == r.N;
	for (size_t i = 0; i < l.N; i++)
	{
		result = result && l.a[i] == r.a[i];
	}
	return result;
}
bool NE(const VectorN& l, const VectorN& r)
{
	return !E(l, r);
}
bool G(const VectorN& l, const VectorN& r)
{
	return l.len() > r.len();
}
bool GE(const VectorN& l, const VectorN& r)
{
	return !L(l, r);
}
bool L( const VectorN& l, const VectorN& r)
{
	return l.len() < r.len();
}
bool LE(const VectorN& l, const VectorN& r)
{
	return !G(l, r);
}

VectorN mul(const VectorN& l, int k)
{
	VectorN t;
	t.Init(l.N);
	for (int i = 0; i < l.N; i++)
	{
		t.a[i] = l.a[i] * k;
	}
		return t;
}