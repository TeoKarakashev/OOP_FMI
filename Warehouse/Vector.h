#pragma once
#include<exception>
#include <iostream>

//class made by me during one of the practicums
//github https://github.com/TeoKarakashev/OOP_FMI/tree/main/vector
//! Helper class that helps working with integer arrays
class Vector
{
	//! stores integer values
	int* arr;
	//! size of the array
	int size;
	//! capacity of the array
	int capacity;

	//! resizes the array if there is not enough space
	void resize();
	//! deletes the array
	void free();
	//! copies the other array to the current one
	void copyFrom(const Vector& other);

public:
	//! Default Constructor for the class
	Vector();
	//! Copy constructor
	Vector(const Vector& other);
	//! operator =
	Vector& operator = (const Vector& other);
	//! Destructor
	~Vector();

	//! Swap two values
	void swap(int& i1, int& i2);
	//! adds element to the array
	void add(const int element);
	//! deletes all elements in the array
	void deleteAll();
	//! getter for the size
	const int getSize()const;
	//! implementation for the [] operator with returns modifable values
	int& operator[](const int index);
	//! implementation for the [] operator with returns unmodifble values
	const int& operator[](int index)const;
	//! deletes element on seratin index
	bool deleteAt(int index);
	//! sorts the array
	void sort();
	//! returns whether the array is empty or not
	bool isEmpty();

};