#pragma once
#include <iostream>
using namespace std;
class Vector
{
	int sizeN;
	int *arr;
public:
	Vector();
	Vector(int );
	Vector(const Vector&);
	int *begin();
	void init(int);
	void add(int , int);
	int getSum();
	int findMax(int&);
	void sortare();
	int getSize();
	int& operator[](int);
	int operator*(const Vector&);
	Vector& operator=(const Vector&);
	friend bool operator!=(const Vector&, const Vector&);
	friend bool operator==(const Vector&, const Vector&);
	friend bool operator<(const Vector&, const Vector&);
	friend bool operator>(const Vector&, const Vector&);
	friend ostream &operator<<(ostream&, const Vector&);
	friend istream &operator>>(istream&, Vector&);
	friend class Matrix;
	~Vector();
};

