#include "DynamicArray.h"
using namespace std;

DynamicArray::DynamicArray() {
	array = new int[10];
	size = 10;
}
DynamicArray::DynamicArray(int size) {
	n = 0;
	this->size = size;
	array = new int[size+1];
	for (int i = 0; i < size+1; i++) {
		array[i] = 0;
	}
}
DynamicArray::DynamicArray(int size, int n) {
	this->n = 0;
	this->size = size;
	array = new int[size+1];
	array[size] = 0;
	for (int i = 0; i < size; i++) {
		array[i] = n;
	}
}
DynamicArray::DynamicArray(const DynamicArray& dynamicArray) {
	n = 0;
	size = dynamicArray.size;
	array = new int[size+1];
	for (int i = 0; i < size; i++) {
		array[i] = dynamicArray.array[i];
	}
}
DynamicArray::DynamicArray(DynamicArray&& dynamicArray){
	n = 0;
	array = new int[dynamicArray.size+1];
	size = dynamicArray.size;
	for (int i = 0; i < size; i++) {
		array[i] = dynamicArray.array[i];
	}
	delete dynamicArray.array;
	dynamicArray.size = NULL;
}
DynamicArray::DynamicArray(int size, int res) {
	this->n = res;
	this->size = size;
	array = new int[size + 1];
	array[size] = 0;
	for (int i = 0; i < size; i++) {
		array[i] = n;
	}
}
DynamicArray::~DynamicArray() {

	n = NULL;
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
	if (newSize <= n + size) {
		n += abs(size - newSize);
		size = newSize;
	}
	else {
		n = 0;
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
	this->n = n;
	DynamicArray temp(n + size);
	for (int i = 0; i < size; i++) {
		temp[i] = array[i];
	}
	array = new int[size + n];
	for (int i = 0; i < size; i++) {
		array[i] = temp[i];
	}
}

int DynamicArray::capacity() {
	return n;
}

void DynamicArray::pushBack(int x) {
	if (size + 1 > size + n) {
		reserve(1);
	}
	array[size] = x;
	size++;
	if (n != 0) {
		n--;
	}
}
int DynamicArray::popBack() {
	int tmp = array[size - 1];
	array[size - 1] = NULL;
	size--;
	return tmp;
}