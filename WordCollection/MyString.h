#pragma once
#include <iostream>
class MyString {

	char* str;
	size_t size;


	void free();
	void copyFrom(const MyString& other);
public:
	MyString();
	MyString(const char* str);
	MyString(const MyString& other);
	MyString& operator=(const MyString& other);
	~MyString();

	size_t getSize() const;
	char& operator[](size_t index); 
	bool operator==(const char* other);
	bool operator==(const MyString& other);
	char operator[](size_t index) const; 
	bool operator<(const MyString& other);

	friend std::ostream& operator<<(std::ostream& stream, const MyString& str);
};
