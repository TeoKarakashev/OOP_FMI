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

MyString::MyString() {
	vals = new char[1];
	vals[0] = '\0';
	size = 0;
}

MyString::MyString(const char* vals) {
	size = strlen(vals);
	this->vals = new char[size + 1];
	strcpy(this->vals, vals);
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

char MyString::operator[](int index) const {
	if (index < 0 || index >= size) {
		throw "Invalid index";
	}
	return vals[index];
}

MyString::~MyString() {
	free();
}

const size_t MyString::getSize() const {
	return size;
}

MyString MyString::substr(int startIndex, int endIndex) const {
	if (endIndex < startIndex) {
		throw "substr cannot have negative size";
	}

	char* substr = new char[size + 1];
	int strSize = 0;
	for (int i = startIndex; i < endIndex; i++) {
		substr[strSize++] = vals[i];
	}
	substr[strSize++] = '\0';
	return MyString(substr);
}

int MyString::strcmp(const MyString& other) const
{
	//ToDo
	return std::strcmp(this->vals, other.vals);
}

int MyString::atoi(const MyString& str) const {
	int res = 0;
	for (int i = 0; i < str.getSize(); i++) {
		res *= 10;
		res += convertCharToInt(str[i]);
	}
	return res;
}

void MyString::strcat(const MyString& str) {

	char* newStr = new char[size + str.size + 1];
	for (int i = 0; i < size; i++) {
		newStr[i] = vals[i];
	}

	for (int i = size; i < str.size + size; i++) {
		newStr[i] = str.vals[i - size];
	}
	newStr[str.size + size] = '\0';
	size = strlen(newStr);
	delete[] vals;
	vals = newStr;
}

void MyString::replaceAt(int index, const char ch) {

	if (index < 0 || index > size - 1) {
		throw "Invalid Index";
	}
	vals[index] = ch;
}

const char* MyString::getVals() const {
	return vals;
}

int MyString::convertCharToInt(const char ch) const
{
	if (ch < '0' || ch > '9') {
		throw "invalid char";
	}
	return ch - '0';
}

char MyString::toUpper(const char ch) const {
	if (ch >= 'a' && ch <= 'z') {
		return (ch - 'a') + 'A';
	}
	return ch;
}

std::ostream& operator<<(std::ostream& stream, const MyString& str) {
	stream << str.vals;
	return stream;
}

std::istream& operator>>(std::istream& stream, MyString& str) {

	delete[] str.vals;
	char buffer[1024];
	stream.getline(buffer, 1024);
	if (buffer[0] == '\0') {
		stream.getline(buffer, 1024);
	}
	str.size = strlen(buffer);
	str.vals = new char[str.size + 1];
	strcpy(str.vals, buffer);

	return stream;
}
