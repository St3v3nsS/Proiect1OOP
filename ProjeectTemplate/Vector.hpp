#ifndef VECTOR_HPP_INCLUDED
#define VECTOR_HPP_INCLUDED

#include <iostream>
#include <algorithm>

using namespace std;

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

#endif // VECTOR_HPP_INCLUDED
