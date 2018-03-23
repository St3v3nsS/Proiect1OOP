#ifndef MATRIX_H
#define MATRIX_H
#include <iostream>
#include <vector>
#include "Vector.h"
#include <algorithm>
using namespace std;

class Matrix
{
    int linii, col;
    Vector *mat;
    public:
        Matrix();
        Matrix(int, int);
		void init(int, int);
		int getLinii();
		int getColumn();
        friend ostream& operator<<(ostream&, const Matrix&);
        friend istream& operator>>(istream&, Matrix&);
        Matrix operator+(const Matrix&);
		Vector& operator[](int);
        ~Matrix();
};

#endif // MATRIX_H
