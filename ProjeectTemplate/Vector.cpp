#include "Vector.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define nullptr NULL
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
ostream &operator<<(ostream& out,const Vector<T>& obj) {
	for (int i = 1; i <= obj.sizeN; i++) {
		out << obj.arr[i] << " ";
	}
	return out;
}

template <typename T>
T operator*(const Vector<T>& obj1,const Vector<T>& obj2) {
	T sum = 0;
	for (T i = 1; i <= obj1.sizeN; i++) {
		sum = sum + obj1.arr[i] * obj2.arr[i];
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
bool operator!=(const Vector<T>& obj1, const Vector<T>& obj2){
    if(obj1.sizeN == obj2.sizeN){
        //obj1.sortare();
        //obj2.sortare();
        for(int i = 1; i <= obj1.sizeN; i++){
            if(obj1.arr[i] != obj2.arr[i])
                return true;
        }
        return false;
    }
    return true;
}

template <typename T>
bool operator==(const Vector<T>& obj1, const Vector<T>& obj2){
    return !operator!=(obj1, obj2);
}

template <typename T>
bool operator<(const Vector<T>& obj1, const Vector<T>& obj2){
    if(obj1.sizeN < obj2.sizeN)
        return true;
    return false;
}
template <typename T>
Vector<T>::~Vector()
{
	delete[] arr;
}
