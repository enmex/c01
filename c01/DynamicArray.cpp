#include "DynamicArray.h"
using namespace std;

DynamicArray::DynamicArray() {
	array = new int[10];
	size = 10;
}
DynamicArray::DynamicArray(int size) {
	this->size = size;
	array = new int[size+1];
	array[size] = 0;
	for (int i = 0; i < size; i++) {
		array[i] = 0;
	}
}
DynamicArray::DynamicArray(int size, int n) {
	this->size = size;
	array = new int[size+1];
	array[size] = 0;
	for (int i = 0; i < size; i++) {
		array[i] = n;
	}
}
DynamicArray::DynamicArray(const DynamicArray& dynamicArray) {
	size = dynamicArray.size;
	array = dynamicArray.array;
}
DynamicArray::DynamicArray(DynamicArray&& dynamicArray){
	this->array = dynamicArray.array;
	this->size = dynamicArray.size;
	delete dynamicArray.array;
	dynamicArray.size = NULL;
}
DynamicArray::~DynamicArray() {
	size = NULL;
	delete array;
}

int DynamicArray::getSize() {
	return this->size;
}

int& DynamicArray::operator[](int i) {
	if (i >= size) {
		return array[size];
	}
	return array[i];
}

void DynamicArray::resize(int newSize) {
	DynamicArray temp(newSize);
	for (int i = 0; i < newSize; i++) {
		temp[i] = array[i];
	}
	delete array;
	size = newSize;
	array = new int[newSize];
	for (int i = 0; i < newSize; i++) {
		array[i] = temp[i];
	}
}
bool operator!=(DynamicArray a, DynamicArray b) {
	return !(a==b);
}

bool operator==(DynamicArray a, DynamicArray b)
{
	if (b.getSize() != a.getSize()) {
		throw "–азные длины массивов, невозможно сравнивать";
	}
	for (int i = 0; i < a.getSize(); i++) {
		if (a[i]!=b[i]) {
			return false;
		}
	}
	return true;
}

bool operator<(DynamicArray a, DynamicArray b) {
	return a.size < b.size;
}
bool operator>(DynamicArray a, DynamicArray b) {
	return a.size > b.size;
}
bool operator<=(DynamicArray a, DynamicArray b) {
	return a.size < b.size || a.size == b.size;
}
bool operator>=(DynamicArray a, DynamicArray b) {
	return a.size > b.size || a.size == b.size;
}
DynamicArray operator+(DynamicArray a, DynamicArray b) {
	DynamicArray tmp(b.size + a.size);
	for (int i = 0; i < a.size; i++) {
		tmp[i] = a[i];
	}
	for (int i = a.size; i < b.size; i++) {
		tmp[i] = b[i];
	}
	return tmp;
}
std::ostream& operator<<(ostream& out, DynamicArray a){
	out << "[";
	for (int i = 0; i < a.size-1; i++) {
		out << a[i] << ", ";
	}
	out << a[a.size - 1] << "]";
	return out;
}

std::istream& operator>>(std::istream& in, DynamicArray& a)
{
	in >> a.size;
	for (int i = 0; i < a.size; i++) {
		in >> a[i];
	}
	return in;
}
