#ifndef MATRIX_HPP
#define MATRIX_HPP
#include <iostream>
#include <vector>
#include "Vector.hpp"
#include <algorithm>

using namespace std;
#define nullptr NULL

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

template <typename T>
Matrix<T>::Matrix()
{
	mat = nullptr;
	linii = col = 0;
}

template <typename T>
Matrix<T>::Matrix(int nrL, int nrC) : linii(nrL), col(nrC) {
	mat = new Vector<T>[nrL + 1];
	for (int i = 1; i <= nrL; i++) {
		mat[i].init(col);
	}
	for (int i = 1; i <= linii; i++)
		for (int j = 1; j <= col; j++)
			mat[i][j] = 0;
}

template <typename T>
int Matrix<T>::getLinii() {
	return linii;
}

template <typename T>
int Matrix<T>::getColumn() {
	return col;
}

template <typename T>
ostream& operator<<(ostream& out, const Matrix<T>& obj) {
	for (int i = 1; i <= obj.linii; i++) {
		for (int j = 1; j <= obj.col; j++)
			out << obj.mat[i][j] << " ";
		out << '\n';
	}
	return out;
}

template <typename T>
void Matrix<T>::init(int nrL, int nrC) {
	linii = nrL;
	col = nrC;
	mat = new Vector<T>[linii + 1];
	for (int i = 1; i <= linii; i++) {
		mat[i].init(col);
	}
}

template <typename T>
istream& operator>>(istream& in, Matrix<T>& obj) {
	for (int i = 1; i <= obj.linii; i++) {
		for (int j = 1; j <= obj.col; j++)
			in >> obj.mat[i][j];
	}
	return in;
}


template <typename T>
Matrix<T> Matrix<T>::operator+(const Matrix<T>& obj1) {
	Matrix<T> temp(obj1.linii, obj1.col);
	for (int i = 1; i <= obj1.linii; i++) {
		for (int j = 1; j <= obj1.col; j++) {
			temp.mat[i][j] = obj1.mat[i][j] + mat[i][j];
		}
	}
	return temp;
}

template <typename T>
Vector<T>& Matrix<T>::operator[](int pos) {
	return mat[pos];
}

template <typename T>
Matrix<T>::~Matrix()
{
	delete[] mat;
	//cout << "\n Matrix deleted";
}

#endif // MATRIX_HPP
