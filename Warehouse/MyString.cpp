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
	vals = nullptr;
	size = 0;
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

char MyString::operator[](int index) const {
	if (index < 0 || index >= size) {
		throw "Invalid index";
	}
	return vals[index];
}

MyString::~MyString(){
	free();
}

size_t MyString::getSize() const {
	return size;
}

MyString MyString::substr(int startIndex, int endIndex) const {
	if (endIndex < startIndex) {
		throw "substr cannot have negative size";
	}

	char* substr = new char[size + 1];
	int strSize = 0;
	for (int i = startIndex; i < endIndex; i++){
		substr[strSize++] = vals[i];
	}
	substr[strSize++] = '\0';
	return MyString(substr);
}

int MyString::strcmp(const MyString& other)
{
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

int MyString::convertCharToInt(const char ch) const
{
	if (ch < '0' || ch > '9') {
		throw "invalid char";
	}
		return ch - '0';
}

char MyString::toUpper(const char ch) {
	if (ch >= 'a' && ch <= 'z') {
		return (ch - 'a') + 'A';
	}
	return ch;
}

std::ostream& operator<<(std::ostream& stream, const MyString& str) {
	stream << str.vals;
	return stream;
}

std::istream& operator>>(std::istream& stream, MyString& str){

	delete[] str.vals;
	char buffer[1024];
	stream >> buffer;
	str.size = strlen(buffer);
	str.vals = new char[str.size + 1];
	strcpy(str.vals, buffer);

	return stream;
}
