#pragma once
#include <iostream>
class DynamicArray
{
private:
	int* array;
	int size;
public:
	DynamicArray();
	DynamicArray(int size);
	DynamicArray(int size, int n);
	DynamicArray(const DynamicArray& dynamicArray);
	DynamicArray(DynamicArray&& dynamicArray) : array(dynamicArray.array), size(dynamicArray.size);
	~DynamicArray();
////////
	int getSize();
	void resize(int newSize);
	int& operator[](int);
}