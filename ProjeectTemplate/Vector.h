#pragma once
#include <iostream>
using namespace std;
template <typename T>
class Vector
{
	int sizeN;
	T *arr;
public:
	Vector();
	Vector(int );
	Vector(const Vector<T>&);
	T *begin();
	void init(int);
	void add(T, int);
	T getSum();
	T findMax(int&);
	void sortare();
	int getSize();
	T& operator[](int);
	friend T operator*(const Vector<T>&,const Vector<T>&);
	Vector<T>& operator=(const Vector<T>&);
	friend bool operator!=(const Vector<T>&, const Vector<T>&);
	friend bool operator==(const Vector<T>&, const Vector<T>&);
	friend bool operator<(const Vector<T>&, const Vector<T>&);
	friend ostream &operator<<(ostream&, const Vector<T>&);
	friend istream &operator>>(istream&, Vector<T>&);
	friend class Matrix;
	~Vector();
};

