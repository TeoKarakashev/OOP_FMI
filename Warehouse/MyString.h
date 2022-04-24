#pragma once

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
	MyString& operator=(const MyString& other);
	~MyString();


};
