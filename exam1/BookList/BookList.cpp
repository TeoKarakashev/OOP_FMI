#include "BookList.h"
#include <fstream>
#include <iostream>
void BookList::free() {
	delete[] books;
}

void BookList::copyFrom(const BookList& other) {
	books = new Book[other.size];
	for (int i = 0; i < other.size; i++){
		books[i] = other.books[i];
	}
	size = other.size;
}

void BookList::resize(){
	capacity *= 2;
	Book* temp = new Book[capacity];
	for (int i = 0; i < size; i++){
		temp[i] = books[i];
	}
	free();
	books = temp;
}

void BookList::add(const Book& book) {
	if (capacity == size) {
		resize();
	}
	books[size++] = book;
}

BookList::BookList(){
	books = new Book[2];
	size = 0;
	capacity = 2;
}

BookList::BookList(const BookList& other) {
	copyFrom(other);
}

BookList& BookList::operator=(const BookList& other)
{
	if (this != &other) {
		free();
		copyFrom(other);
	}
	return *this;
}

BookList::~BookList(){
	free();
}

void BookList::writeInFIle(const char* name) {
	std::ofstream outFile(name);
	if (!outFile.is_open()) {
		throw "File is not opened";
	}
	for (int i = 0; i < size; i++){
		if (books[i].getTiraj() >= 1000) {
			outFile << books[i].getTitle() << " " << books[i].getAuthor() << " " << books[i].getTiraj();
			outFile << std::endl;
		}
	}
}

void BookList::readFromFile(const char* name) {
	std::ifstream inStream(name, std::ios::binary);
	Book buffer;
	int sizeBuff;
	inStream.read((char*)&sizeBuff, sizeof(int));
	for (size_t i = 0; i < sizeBuff; i++){
	inStream.read((char*)&buffer, sizeof(Book));
	add(buffer);
	}
}
