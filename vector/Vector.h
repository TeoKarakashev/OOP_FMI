#pragma once
#include<exception>
#include <iostream>
class Vector
{
	int* arr = nullptr;
	int size;
	int capacity;

	void resize();
	void free();
	void copyFrom(const Vector&);
	void swap(int& i1, int& i2);

public:
	Vector();
	Vector(const Vector&);
	Vector& operator = (const Vector&);
	~Vector();

	void push_back(const int);
	int getSize()const;
	int& operator [](const int);
	const int& operator [](int)const;
	bool deleteAt(int index);
	bool pop_back();
	int findItem(int el) const;
	void clear();
	void sort() ;
	void print() const;
};