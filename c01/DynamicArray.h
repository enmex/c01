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
	DynamicArray(DynamicArray&& dynamicArray);
	~DynamicArray();
	////////
	int getSize();
	void resize(int newSize);
	void reserve(int);
	int capacity();


	int& operator[](int);
	friend bool operator==(DynamicArray, DynamicArray);
	friend bool operator!=(DynamicArray, DynamicArray);
	friend bool operator<(DynamicArray, DynamicArray);
	friend bool operator>(DynamicArray, DynamicArray);
	friend bool operator<=(DynamicArray, DynamicArray);
	friend bool operator>=(DynamicArray, DynamicArray);
	friend const DynamicArray operator+(DynamicArray&, DynamicArray&);
	friend std::ostream& operator<<(std::ostream& out, DynamicArray&);
	friend std::istream& operator>>(std::istream& in, DynamicArray&);
};