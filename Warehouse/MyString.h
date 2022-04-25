#pragma once
#include<iostream>

class MyString {
	char* vals;
	size_t size;

	void copyFrom(const MyString& other);
	void free();

public:
	//constructors
	MyString(const char* vals);
	MyString(const MyString& other);
	MyString& operator=(const MyString& other);
	~MyString();

	friend std::ostream& operator<<(std::ostream& stream, const MyString& str);
};
