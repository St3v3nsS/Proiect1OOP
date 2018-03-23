#include "Matrix.h"
#include <iostream>
#include "Vector.h"
#include <vector>
#include <algorithm>
using namespace std;

Matrix::Matrix()
{
	mat = nullptr;
	linii = col = 0;
}

Matrix::Matrix(int nrL, int nrC) : linii(nrL), col(nrC) {
	mat = new Vector[nrL + 1];
	for (int i = 1; i <= nrL; i++) {
		mat[i].init(col);
	}
	for (int i = 1; i <= linii; i++)
		for (int j = 1; j <= col; j++)
			mat[i][j] = 0;
}

int Matrix::getLinii() {
	return linii;
}

int Matrix::getColumn() {
	return col;
}

ostream& operator<<(ostream& out, const Matrix& obj) {
	for (int i = 1; i <= obj.linii; i++) {
		for (int j = 1; j <= obj.col; j++)
			out << obj.mat[i][j] << " ";
		out << '\n';
	}
	return out;
}

void Matrix::init(int nrL, int nrC) {
	linii = nrL;
	col = nrC;
	mat = new Vector[linii + 1];
	for (int i = 1; i <= linii; i++) {
		mat[i].init(col);
	}
}

istream& operator>>(istream& in, Matrix& obj) {
	for (int i = 1; i <= obj.linii; i++) {
		for (int j = 1; j <= obj.col; j++)
			in >> obj.mat[i][j];
	}
	return in;
}

Matrix Matrix::operator+(const Matrix& obj1) {
	Matrix temp(obj1.linii, obj1.col);
	for (int i = 1; i <= obj1.linii; i++) {
		for (int j = 1; j <= obj1.col; j++) {
			temp.mat[i][j] = obj1.mat[i][j] + mat[i][j];
		}
	}
	return temp;
}

Vector& Matrix::operator[](int pos) {
	return mat[pos];
}

Matrix::~Matrix()
{
	delete[] mat;
	//cout << "\n Matrix deleted";
}
