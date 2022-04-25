#include "MyString.h"
#include <iostream>
#pragma warning(disable: 4996)

void MyString::copyFrom(const MyString& other) {
	vals = new char[other.size + 1];
	strcpy(vals, other.vals);
	size = other.size;
}

void MyString::free() {
	delete[] vals;
}

MyString::MyString(const char* vals) {
	size = strlen(vals);
	this->vals = new char[size + 1];
	strcpy(this->vals, vals);
}

MyString::MyString(const MyString& other){
	copyFrom(other);
}

MyString& MyString::operator=(const MyString& other) {

	if (this != &other) {
		free();
		copyFrom(other);
	}
	return *this;
}

MyString::~MyString(){
	free();
}

std::ostream& operator<<(std::ostream& stream, const MyString& str) {
	stream << str.vals;
	return stream;
}
