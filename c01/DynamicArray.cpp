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
DynamicArray::DynamicArray(DynamicArray&& dynamicArray) : array(dynamicArray.array), size(dynamicArray.size) {
	this->size = 0;
	this->array = nullptr;
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

}