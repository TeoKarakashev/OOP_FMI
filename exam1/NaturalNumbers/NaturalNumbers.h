#pragma once
#include <iostream>
class NaturalNumbers{
	char* name;
	int* numbers;
	size_t sizeOfNumbers;
	int capacity;

	void free();
	void copyFrom(const NaturalNumbers& other);
	void resize();
	bool contains(int number);
	bool add(int number);
public:
	NaturalNumbers();
	NaturalNumbers(int* numbers,size_t sizeOfNumbers,const char* name);
	NaturalNumbers(const NaturalNumbers& other);
	NaturalNumbers& operator=(const NaturalNumbers& other);
	~NaturalNumbers();
	NaturalNumbers& operator+=(const NaturalNumbers& other);
	bool operator[](int number);

	friend std::istream& operator>>(std::istream& stream, NaturalNumbers& set);
	friend std::ostream& operator<<(std::ostream& stream, const NaturalNumbers& set);
};

const NaturalNumbers operator+(const NaturalNumbers& n1, const NaturalNumbers& n2);
