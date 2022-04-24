#pragma once
#include "Book.h"
class BookList {
	Book* books;
	int size;
	int capacity;
	void free();
	void copyFrom(const BookList& other);
	void resize();

public:
	void add(const Book& book);
	BookList();
	BookList(const BookList& other);
	BookList& operator=(const BookList& other);
	~BookList();

	void writeInFIle(const char* name);
	void readFromFile(const char* name);

};


