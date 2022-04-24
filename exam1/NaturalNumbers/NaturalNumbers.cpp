#include "NaturalNumbers.h"
#include <iostream>
#include <fstream>
#pragma warning (disable: 4996)
void NaturalNumbers::free() {
	delete[] numbers;
	delete[] name;
}

void NaturalNumbers::copyFrom(const NaturalNumbers& other){
	numbers = new int[other.capacity];
	capacity = other.capacity;
	for (int i = 0; i < other.sizeOfNumbers; i++){
		numbers[i] = other.numbers[i];
	}
	name = new char [strlen(other.name) + 1];
	strcpy(name, other.name);
	sizeOfNumbers = other.sizeOfNumbers;
}

void NaturalNumbers::resize(){
	capacity *= 2;
	int* temp = new int[capacity];
	for (int i = 0; i < sizeOfNumbers; i++){
		temp[i] = numbers[i];
	}
	delete[] numbers;
	numbers = temp;
}

bool NaturalNumbers::add(int number){
	if (!contains(number)) {
		if (capacity == sizeOfNumbers) {
			resize();
		}
		numbers[sizeOfNumbers++] = number;
		return true;
	}
	return false;
}

bool NaturalNumbers::contains(int number){
	for (int i = 0; i < sizeOfNumbers; i++){
		if (numbers[i] == number) {
			return true;
		}
	}
	return false;
}


NaturalNumbers::NaturalNumbers(){
	numbers = new int[2];
	name = new char[11];
	sizeOfNumbers = 0;
	strcpy(name, "Empty set");
	capacity = 2;
}

NaturalNumbers::NaturalNumbers(int* numbers, size_t sizeOfNumbers,const char* name){
	capacity = (sizeOfNumbers * 2) + 2;
	this->numbers = new int[capacity];
	this->name = new char[strlen(name) + 1];
	for (int i = 0; i < sizeOfNumbers; i++) {
		add(numbers[i]);
	}
	this->sizeOfNumbers = sizeOfNumbers;
	strcpy(this->name, name);
}

NaturalNumbers::NaturalNumbers(const NaturalNumbers& other){
	copyFrom(other);
}

NaturalNumbers& NaturalNumbers::operator=(const NaturalNumbers& other)
{
	if (this != &other) {
		free();
		copyFrom(other);
	}
	return *this;
}

NaturalNumbers::~NaturalNumbers(){
	free();
}

NaturalNumbers& NaturalNumbers::operator+=(const NaturalNumbers& other)
{
	for (size_t i = 0; i < other.sizeOfNumbers; i++){
		add(other.numbers[i]);
	}
	char newName[1024] = {"Union of "};
	strcat(newName, name);
	strcat(newName, " and ");
	strcat(newName, other.name);
	delete[] name;
	name = new char[strlen(newName) + 1];
	strcpy(name, newName);
	return *this;
}

bool NaturalNumbers::operator[](int number)
{
	return contains(number);
}

std::istream& operator>>(std::istream& stream, NaturalNumbers& set){
	for (int i = set.sizeOfNumbers; i < set.capacity; i++){
		int number;
		stream >> number;
		set.add(number);
	}
	char buffer[1024];
	for (int i = 0; i < 10; i++){
		stream >> buffer[i];
	}
	delete[] set.name;
	set.name = new char[strlen(buffer) + 1];
	return stream;
}

std::ostream& operator<<(std::ostream& stream, const NaturalNumbers& set)
{
	std::cout << "{ ";
	for (int i = 0; i < set.sizeOfNumbers; i++){
		stream << set.numbers[i] << " ";
	}
	std::cout << "}";
	stream << " with name: ";
	stream << set.name<<std::endl;
	return stream;
}

const NaturalNumbers operator+(const NaturalNumbers& n1, const NaturalNumbers& n2)
{
	NaturalNumbers result(n1);
	result += n2;
	return result;
}
