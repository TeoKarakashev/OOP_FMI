#pragma once
#include<exception>
#include <iostream>
class Vector
{
	int* arr;
	int size;
	int capacity;

	void resize();
	void free();
	void copyFrom(const Vector& other);
	void swap(int& i1, int& i2);

public:
	Vector();
	Vector(const Vector& other);
	Vector& operator = (const Vector& other);
	~Vector();

	void add(const int element);
	int getSize()const;
	int& operator[](const int index);
	const int& operator[](int index)const;
	bool deleteAt(int index);
	void sort();
	bool isEmpty();

};