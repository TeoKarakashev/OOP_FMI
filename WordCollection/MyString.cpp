#include "MyString.h"
#include <iostream>
#pragma warning(disable: 4996)
void MyString::free() {
	delete[] str;
}

void MyString::copyFrom(const MyString& other) {
	str = new char[other.size + 1];
	strcpy(str, other.str);
	size = other.size;
}



MyString::MyString() {
	str = new char[1];
	str[0] = '\0';
	size = 0;
}

MyString::MyString(const char* str) {
	size = strlen(str);
	this->str = new char[size + 1];
	strcpy(this->str, str);
}

MyString::MyString(const MyString& other) {
	copyFrom(other);
}

MyString& MyString::operator=(const MyString& other) {
	if (this != &other) {
		free();
		copyFrom(other);
	}
	return *this;
}

MyString::~MyString() {
	free();
}

size_t MyString::getSize() const {
	return size;
}

char& MyString::operator[](size_t index)
{
	if (index >= size)
		throw "Invalid index";

	return str[index];
}

bool MyString::operator==(const char* other)
{

	return strcmp(str, other) == 0;
}
bool MyString::operator==(const MyString& other){

	if (other.size != size) {
		return false;
	}
	for (int i = 0; i < size; i++) {
		if (str[i] - other[i] != 0)
			return false;
	}
	return true;
}

char MyString::operator[](size_t index) const
{
	if (index >= size)
		throw "Invalid index";

	return str[index];
}

bool MyString::operator<(const MyString& other)
{
	return strcmp(str, other.str) == -1;
}

char* MyString::getStr() const
{
	return str;
}


std::ostream& operator<<(std::ostream& stream, const MyString& str) {
	for (int i = 0; i < str.size; i++) {
		stream << str[i];
	}
	return stream;
}

std::istream& operator>>(std::istream& stream,  MyString& str)
{
	char word[100];
	std::cin >> word;
	MyString temp(word);
	str = temp;
	return stream;
}
