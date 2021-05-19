/*
У  всіх  завданнях,  крім  вказаних  в  завданні  операцій,  обов’язково мають бути реалізовані наступні методи:
-Init();
-Read();
-Displау();
-toString()
	Поля:
 N – розмірність вектора,
 a – масив дійсних чисел, який реалізує вектор.
	Обов’язково мають бути реалізовані:
- множення на скаляр,
- порівняння векторів,
- обчислення довжини вектора,
- порівняння довжин векторів.
- "TO STRING!"
*/

#pragma once
#include <string>
#include <iostream>
#include<iomanip>
using namespace std;
class VectorN
{
private:

	int N;	 // розмірність вектора
	double *a; // масив дійсних чисел, який реалізує вектор

public:

	void setN(int value) { N = value; };

	void Init(int N);
	void Read();
	void Display() const;
	void Destroy();

	double len() const;	// обчислення довжини вектора
// порівняння векторів
	friend bool E(const VectorN& l, const VectorN& r);		
	friend bool NE(const VectorN& l, const VectorN& r);
// порівняння довжин векторів
	friend bool G(const VectorN& l, const VectorN& r);	
	friend bool GE(const VectorN& l, const VectorN& r);
	friend bool L(const VectorN& l, const VectorN& r);
	friend bool LE(const VectorN& l, const VectorN& r);
	friend VectorN mul(const VectorN& l, int k); // множення на скаляр
	string toString() const;
};
