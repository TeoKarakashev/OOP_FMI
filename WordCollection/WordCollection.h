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
	void shift(int index);

public:
	WordCollection();
	WordCollection(const WordCollection& other);
	WordCollection& operator=(const WordCollection& other);
	~WordCollection();

	MyString& operator[](size_t index); 
	MyString operator[](size_t index) const; 
	bool operator[](const char* str) const; 

	WordCollection& operator+=(const WordCollection& colection2);
	WordCollection& operator*=(const MyString& word);

	size_t getSize() const;

	friend std::ostream& operator<<(std::ostream& stream, const WordCollection& colection);

};

WordCollection operator+(const WordCollection& collection1, const WordCollection& collection2);

