#include "DynamicArray.h"
using namespace std;

DynamicArray::DynamicArray() {
	array = new int[10];
	size = 10;
}
DynamicArray::DynamicArray(int size) {
	this->size = size;
	array = new int[size+1];
	for (int i = 0; i < size+1; i++) {
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
	array = new int[size+1];
	for (int i = 0; i < size; i++) {
		array[i] = dynamicArray.array[i];
	}
}
DynamicArray::DynamicArray(DynamicArray&& dynamicArray){
	array = new int[dynamicArray.size+1];
	size = dynamicArray.size;
	for (int i = 0; i < size; i++) {
		array[i] = dynamicArray.array[i];
	}
	delete dynamicArray.array;
	dynamicArray.size = NULL;
}
DynamicArray::~DynamicArray() {

	size = NULL;
	
	delete array;
}

int DynamicArray::getSize() {
	return size;
}

int& DynamicArray::operator[](int i) {
	return array[i];
}

void DynamicArray::resize(int newSize) {
	DynamicArray temp(newSize);
	for (int i = 0; i < size; i++) {
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
		throw "Разные длины массивов, невозможно сравнивать";
	}
	for (int i = 0; i < a.getSize(); i++) {
		if (a[i]!=b[i]) {
			return false;
		}
	}
	return true;
}

bool operator<(DynamicArray a, DynamicArray b) {
	string _a;
	string _b;
	for (int i = 0; i < a.size; i++) {
		_a += a[i];
	}
	for (int i = 0; i < b.size; i++) {
		_b += b[i];
	}
	return _a < _b;
}
bool operator>(DynamicArray a, DynamicArray b) {
	return b < a;
}
bool operator<=(DynamicArray a, DynamicArray b) {
	if (a < b) {
		return true;
	}
	try {
		a == b;
	}
	catch (exception e) {
		return a.size < b.size;
	}
	return a == b;
}
bool operator>=(DynamicArray a, DynamicArray b) {
	return b <= a;
}
const DynamicArray operator+(DynamicArray& a, DynamicArray& b) {
	DynamicArray tmp(a.size + b.size);
	for (int i = 0; i < a.size; i++) {
		tmp[i] = a[i];
	}
	for (int i = a.size; i < b.size+a.size; i++) {
		tmp[i] = b[i-a.size];
	}
	return DynamicArray(tmp);
}
std::ostream& operator<<(std::ostream& out, DynamicArray& a){
	out << "[";
	for (int i = 0; i < a.size-1; i++) {
		out << a[i] << ", ";
	}
	out << a[a.size - 1]; //баг не подается размер
	out << "]\n";
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

//задание 1.2
void DynamicArray::reserve(int n) {
	resize(2*size-n);
}

