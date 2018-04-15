// Proiect1.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

ifstream in("date.in");
ofstream out("date.out");
#define nullptr NULL

template<typename T>
class Matrix;

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
	T operator*(const Vector<T>&);
	Vector<T>& operator=(const Vector<T>&);
	bool operator!=(const Vector<T>&);
	bool operator==(const Vector<T>&);
	bool operator<(const Vector<T>&);
	template <class U>
	friend ostream &operator<<(ostream&, const Vector<U>&);
	template <class U>
	friend istream &operator>>(istream&, Vector <U>&);
	friend class Matrix<T>;
	~Vector();
};

template <typename T>
Vector<T>::Vector() {
	sizeN = 0;
 	arr = nullptr;
}

template <typename T>
Vector<T>::Vector(int len) : sizeN(len){
	arr = nullptr;
	arr = new T[sizeN + 1];
	for (int i = 1; i <= sizeN; i++)
		arr[i] = 0;
}
template <typename T>
T* Vector<T>::begin()
{
	return arr;
}
template <typename T>
void Vector<T>::add(T x, int pos) {
	arr[pos] = x;
}

template <typename T>
T Vector<T>::findMax(int &pos) {
	T max = arr[1];
	pos = 1;
	for(int i = 2; i <= sizeN; i++)
		if (arr[i] > max) {
			max = arr[i];
			pos = i;
		}
	return max;
}

template <typename T>
int Vector<T>::getSize()
{
	return sizeN;
}

template <typename T>
void Vector<T>::sortare() {
	sort(arr + 1, arr + sizeN  + 1);
}

template <typename T>
T& Vector<T>::operator[](int pos) {
	return arr[pos];
}

template <typename T>
istream& operator>>(istream& in, Vector<T>& obj) {
	for (int i = 1; i <= obj.sizeN; i++) {
		in >> obj.arr[i];
	}
	return in;
}

template <typename T>
ostream& operator<<(ostream& out, const Vector<T>& obj) {
	for (int i = 1; i <= obj.sizeN; i++) {
		out << obj.arr[i] << " ";
	}
	return out;
}

template <typename T>
T Vector<T>:: operator*(const Vector<T>& obj2) {
	T sum = 0;
	for (int i = 1; i <= sizeN; i++) {
		sum = sum + arr[i] * obj2.arr[i];
	}
	return sum;
}

template <typename T>
T Vector<T>::getSum() {
	T sum = 0;
	for (int i = 1; i <= sizeN; i++) {
		sum += arr[i];
	}
	return sum;
}
template <typename T>
void Vector<T>::init(int x){
    arr = new T[x + 1];
    sizeN = x;
    for(int i = 1; i <= x; i++){
        arr[i] = 0;
    }
}
template <typename T>
Vector<T>::Vector(const Vector<T>& obj){
    sizeN = obj.sizeN;
    for(int i = 1; i <= sizeN; i++){
        arr[i] = obj.arr[i];
    }
}
template <typename T>
Vector<T>& Vector<T>::operator=(const Vector<T>& obj){
    return *this;
}
template <typename T>
bool Vector<T>::operator!=(const Vector<T>& obj2){
    if(sizeN == obj2.sizeN){
        //obj1.sortare();
        //obj2.sortare();
        for(int i = 1; i <= sizeN; i++){
            if(arr[i] != obj2.arr[i])
                return true;
        }
        return false;
    }
    return true;
}

template <typename T>
bool Vector<T>::operator==(const Vector<T>& obj2){
    return !operator!=(*this, obj2);
}

template <typename T>
bool Vector<T>::operator<(const Vector<T>& obj2){
    if(sizeN < obj2.sizeN)
        return true;
    if(sizeN == obj2.sizeN)
        return arr[1]<obj2.arr[1];
    return false;
}
template <typename T>
Vector<T>::~Vector()
{
	delete[] arr;
}

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
        template <class U>
        friend ostream& operator<<(ostream&, const Matrix<U>&);
        template <class U>
        friend istream& operator>>(istream&, Matrix<U>&);
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


bool solve(Matrix<double>& matrix, Vector<double>& x, Vector<double>& y) {
	int result = 1;
	bool ok = 1;
	for(int i = 1; i <= matrix.getLinii(); i++){
		result = matrix[i] * x;
		if (result != y[i])
			return false;
	}
	return true;
}

int main()
{
	int n;
	double x, nr;
	cout << "Se vor citi cele N obiecte din fisier. Asemenea si obiectul de tip matrice,\n" <<
		"dar si cele doua obiecte de tip vector folosite pentru verificarea ecuatiei.\n" <<
		"*****************************************************************************\n" <<
		"Se citeste N(nr de obiecte), dimensiunea fiecarui obiect si elementele obiectului.\n" <<
		"Se citesc nr de linii si de coloane ale matricei, elementele matricei si cele doua obiecte.\n";
	in >> n;
	Vector<double> *arrey = new Vector<double>[n + 1];
	for (int i = 1; i <= n; i++) {
		in >> x;
		arrey[i].init(x);
		in >> arrey[i];
	}
	arrey[1].sortare();
	out << arrey[1] << "\n" << arrey[2] << '\n';
	out << arrey[1] * arrey[2] << "\n";
	int lin, col;
	in >> lin >> col;
	Matrix<double> M(lin, col);
	in >> M;
	out <<'\n' << M;
	int a, b;
	in >> a >> b;
	Vector <double> arr1(a), arr2(b);
	in >> arr1 >> arr2;
	if (solve(M, arr1, arr2) == 1) {
		out << "\nEcuatia este corecta!\n";
	}
	else {
		out << "\nEcuatia nu este corecta!\n";
	}

	int option, num, pos = 0;
	double elem;
	Vector<double> temp;
	bool sortat = 0;
	do {
		cout << "********************MENIU****************\n"
			<< "1. Aflati maximul dintr-un obiect!\n"
			<< "2. Aflati suma vectorului\n"
			<< "3. Sortati un obiect\n"
			<< "4. Sortati obiectele crescator\n"
			<< "5. Afisati obiectele\n"
			<< "6. Exit!\n";
		cin >> option;
		if (option < 1 || option > 6) {
			cout << "Numar gresit!\n";
		}
		switch (option)
		{
		case 1: cout << "Introduceti un numar: ";

			cin >> num;
			if (num > n) {
				cout << "Error!\n";
				break;
			}
			try
			{
				elem = arrey[num].findMax(pos);
			}
			catch (...)
			{
				cout << "Error!\n";
			}
			cout << "Elementul maxim este: " << elem << " si se afla pe pozitia " << pos << "\n";
			break;
		case 2: cout << "Introduceti un numar: ";

			cin >> num;
			if (num > n) {
				cout << "Error!\n";
				break;
			}
			try
			{
				cout << arrey[num].getSum() << '\n';
			}
			catch (const exception& e)
			{
				cout << e.what() << " ";
			}
			break;
		case 3: cout << "Introduceti un numar: ";

			cin >> num;
			if (num > n) {
				cout << "Error!\n";
				break;
			}
			try
			{
				arrey[num].sortare();
			}
			catch (const exception& e)
			{
				cout << e.what() << " ";
			}
			cout << arrey[num] << '\n';
			break;
		case 4:
			for (int i = 1; i <= n; i++)
				arrey[i].sortare();
			do {
				sortat = 1;
				for(int i = 1; i < n; i++)
					if (arrey[i] < arrey[i + 1]) {
						;
					}
					else {
						temp = arrey[i];
						arrey[i] = arrey[i + 1];
						arrey[i + 1] = temp;
						sortat = 0;
					}
			} while (sortat == 0);
			break;
		case 5: for (int i = 1; i <= n; i++)
			cout << arrey[i] << '\n';
			break;
		case 6: exit(EXIT_SUCCESS);
			break;
		default:
			break;
		}
	} while (option <= 6);
    return 0;
}



