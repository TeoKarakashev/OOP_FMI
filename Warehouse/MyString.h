#pragma once
#include<iostream>

class MyString {
	char* vals;
	size_t size;

	void copyFrom(const MyString& other);
	void free();

public:
	MyString();
	MyString(const char* vals);
	MyString(const MyString& other);
	~MyString();

	MyString& operator=(const MyString& other);
	char operator[](int index) const;
	size_t getSize() const;
	MyString substr(int startIndex, int endIndex) const ;
	int strcmp(const MyString& other);
	int atoi(const MyString& str) const ;
	int convertCharToInt(const char ch) const;
	char toUpper(const char ch);
	friend std::ostream& operator<<(std::ostream& stream, const MyString& str);
	friend std::istream& operator>>(std::istream& stream, MyString& str);
};
