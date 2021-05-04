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
#include <vector>
#include <string>
#include <iostream>
#include<iomanip>
using namespace std;
class VectorN
{
private:

	int N,	 // розмірність вектора
		k;	 // скаляр
	vector<int> a; // масив дійсних чисел, який реалізує вектор
		
public:
	int getN() const { return N; };
	//int getA() const { return a; };
	int getK() const { return k; };

	void setN(int value) { N = value; };
	void setA(int value, int i) { a.insert(a.begin()+i, value); };
	void setK(int value) { k = value; };

	void Init(int N, int  el, int i);
	void Read();
	void Display() const;

	void mScalar(int k);			// множення на скаляр
	int  lVector();					// обчислення довжини вектора
	bool Compare(VectorN name);		// порівняння векторів
	bool lCompare(VectorN name);	// порівняння довжин векторів
	string toString() const;

};

