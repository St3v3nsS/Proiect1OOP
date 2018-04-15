#ifndef MATRIX_H
#define MATRIX_H
#include <iostream>
#include <vector>
#include "Vector.h"
#include <algorithm>
using namespace std;
template <typename T>
class Matrix
{
    int linii, col;
    Vector<T> *mat;
    public:
        Matrix();
        Matrix(int, int);
		void init(int, int);
		int getLinii();
		int getColumn();
        friend ostream& operator<<(ostream&, const Matrix<T>&);
        friend istream& operator>>(istream&, Matrix<T>&);
        Matrix operator+(const Matrix<T>&);
		Vector<T>& operator[](int);
        ~Matrix();
};

#endif // MATRIX_H
