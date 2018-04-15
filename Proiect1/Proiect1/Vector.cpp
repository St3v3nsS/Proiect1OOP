#include "Vector.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

Vector::Vector() {
	sizeN = 0;
 	arr = nullptr;
}

Vector::Vector(int len) : sizeN(len){
	arr = nullptr;
	arr = new int[sizeN + 1];
	for (int i = 1; i <= sizeN; i++)
		arr[i] = 0;
}

int* Vector::begin()
{
	return arr;
}
void Vector::add(int x, int pos) {
	arr[pos] = x;
}

int Vector::findMax(int &pos) {
	int max = arr[1];
	pos = 1;
	for(int i = 2; i <= sizeN; i++)
		if (arr[i] > max) {
			max = arr[i];
			pos = i;
		}
	return max;
}

int Vector::getSize()
{
	return sizeN;
}

void Vector::sortare() {
	sort(arr + 1, arr + sizeN  + 1);
}

int& Vector::operator[](int pos) {
	
		return arr[pos];
	
}

istream& operator>>(istream& in, Vector& obj) {
	for (int i = 1; i <= obj.sizeN; i++) {
		in >> obj.arr[i];
	}
	return in;
}

ostream &operator<<(ostream& out,const Vector& obj) {
	for (int i = 1; i <= obj.sizeN; i++) {
		out << obj.arr[i] << " ";
	}
	return out;
}

int Vector::operator*(const Vector& obj1) {
	int sum = 0;
	for (int i = 1; i <= obj1.sizeN; i++) {
		sum = sum + obj1.arr[i] * arr[i];
	}
	return sum;
}

int Vector::getSum() {
	int sum = 0;
	for (int i = 1; i <= sizeN; i++) {
		sum += arr[i];
	}
	return sum;
}

void Vector::init(int x){
    arr = new int[x + 1];
    sizeN = x;
    for(int i = 1; i <= x; i++){
        arr[i] = 0;
    }
}

Vector::Vector(const Vector& obj){
    sizeN = obj.sizeN;
    for(int i = 1; i <= sizeN; i++){
        arr[i] = obj.arr[i];
    }
}

Vector& Vector::operator=(const Vector& obj){
    return *this;
}

bool operator!=(const Vector& obj1, const Vector& obj2){
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

bool operator==(const Vector& obj1, const Vector& obj2){
    return !operator!=(obj1, obj2);
}

bool operator<(const Vector& obj1, const Vector& obj2){
    if(obj1.sizeN < obj2.sizeN)
        return true;
	if (obj1.sizeN > obj2.sizeN)
		return false;
	
	if (obj1.sizeN == obj2.sizeN) {
		if (obj1.arr[1] >= obj2.arr[1]) {
				return false;
			}
	}
	return true;
}
bool operator>(const Vector& obj1, const Vector& obj2) {
	if (obj1.sizeN < obj2.sizeN)
		return false;
	if (obj1.sizeN > obj2.sizeN)
		return true;
	if (obj1.sizeN == obj2.sizeN) {
		for (int i = 1; i <= obj1.sizeN; i++)
			for (int j = 1; j <= obj2.sizeN; j++)
				if (obj1.arr[i] <= obj2.arr[j]) {
					cout << "ok\n";
					return false;
				}
	}
	return true;
}

Vector::~Vector()
{
	delete[] arr;
	//cout << "\n Vector deleted";
}
