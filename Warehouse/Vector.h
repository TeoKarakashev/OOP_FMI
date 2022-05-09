#pragma once
#include<exception>
#include <iostream>

//class made by me during one of the practicums
//github https://github.com/TeoKarakashev/OOP_FMI/tree/main/vector
class Vector
{
	int* arr;
	int size;
	int capacity;

	void resize();
	void free();
	void copyFrom(const Vector& other);

public:
	Vector();
	Vector(const Vector& other);
	Vector& operator = (const Vector& other);
	~Vector();

	void swap(int& i1, int& i2);
	void add(const int element);
	void deleteAll();
	const int getSize()const;
	int& operator[](const int index);
	const int& operator[](int index)const;
	bool deleteAt(int index);
	void sort();
	bool isEmpty();

};