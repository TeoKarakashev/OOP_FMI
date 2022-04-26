#pragma once
#include<iostream>

class MyString {
	char* vals;
	size_t size;

	void copyFrom(const MyString& other);
	void free();

public:
	//constructors
	MyString();
	MyString(const char* vals);
	MyString(const MyString& other);
	~MyString();

	MyString& operator=(const MyString& other);
	char operator[](int index) const;
	size_t getSize() const;

	friend std::ostream& operator<<(std::ostream& stream, const MyString& str);
};
