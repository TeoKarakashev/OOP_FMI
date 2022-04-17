#pragma once
#include "MyString.h"
#include <iostream>
class WordCollection {
	MyString* words;
	size_t size;
	size_t capacity;

	void free();
	void copyFrom(const WordCollection& other);
	void resize();
	void add(const MyString& word);
	int getCorrectIndexToAddWord(const MyString& word);
	void shiftRight(int index);
	void shiftLeft(int index);
	bool contains(const char* word, int& index) const;

public:
	WordCollection();
	WordCollection(const WordCollection& other);
	WordCollection& operator=(const WordCollection& other);
	~WordCollection();

	MyString& operator[](int index); 
	MyString operator[](int index) const; 
	bool operator[](const char* str) const; 

	WordCollection& operator+=(const WordCollection& colection2);
	WordCollection& operator-=(const WordCollection& colection2);
	WordCollection& operator*=(const MyString& word);
	WordCollection& operator/=(const char* word);
	WordCollection& operator<<(const char* str);

	friend std::ostream& operator<<(std::ostream& stream, const WordCollection& colection);
	friend std::istream& operator>>(std::istream& stream, WordCollection& colection);
};

WordCollection operator+(const WordCollection& collection1, const WordCollection& collection2);
WordCollection operator-(const WordCollection& collection1, const WordCollection& collection2);

