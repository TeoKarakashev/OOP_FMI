#pragma once
#include<iostream>

//! Helper class that helps working with String
class MyString {
	//! Storage for all the chars in the String
	char* vals;
	//! Size of the string
	size_t size;

	//! Copies the other string the the current
	void copyFrom(const MyString& other);
	//! deletes the string
	void free();

public:
	//! Default constructor for the class
	MyString();
	//! Constructor with parameters
	MyString(const char* vals);
	//! Copy Contructor 
	MyString(const MyString& other);
	//! Destructor
	~MyString();

	//! operator =
	MyString& operator=(const MyString& other);
	//! Implementation for the [] operator
	char operator[](int index) const;
	//! Getter for the size
	const size_t getSize() const;
	//! getter gor the String
	const char* getVals() const;
	
	//! Returns a substring of the current string bettween start and end index 
	MyString substr(int startIndex, int endIndex) const;
	
	//! Returns which string bigger using ASCII comparisson
	int strcmp(const MyString& other) const;
	//! Parses the String to integer
	int atoi(const MyString& str) const ;
	//! concats two string
	void strcat(const MyString& str);
	//! replaces character of a string with another 
	void replaceAt(int index,const char ch);
	//! converst a single character to integer
	int convertCharToInt(const char ch) const;
	//! converts a single character to its Upper cas
	char toUpper(const char ch) const;

	//! Implementation for the == operator
	bool operator==(const MyString& other) const;
	//! Implementation for the != operator
	bool operator!=(const MyString& other) const;
	//! Implementation for the << operator
	friend std::ostream& operator<<(std::ostream& stream, const MyString& str);
	//! Implementation for the >> operator
	friend std::istream& operator>>(std::istream& stream, MyString& str);
};
