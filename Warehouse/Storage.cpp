#include "Storage.h"
#include <fstream>
#include <iostream>

void Storage::copyFrom(const Storage& other) {
	products = new Product[other.capacity];
	for (int i = 0; i < other.size; i++) {
		add(other.products[i]);
	}
	size = other.size;
	capacity = other.capacity;
}

void Storage::free() {
	delete[] products;
}

void Storage::resize() {
	capacity *= 2;
	Product* temp = new Product[capacity];
	for (int i = 0; i < size; i++) {
		temp[i] = products[i];
	}
	free();
	products = temp;
}

Storage::Storage() {
	products = new Product[2];
	size = 0;
	capacity = 2;
}

Storage::Storage(const Storage& other) {
	copyFrom(other);
}

Storage& Storage::operator=(const Storage& other) {
	if (this != &other) {
		free();
		copyFrom(other);
	}
	return *this;
}

Storage::~Storage() {
	free();
}

void Storage::add(const Product& product) {
	if (size == capacity) {
		resize();
	}
	products[size++] = product;
}

void Storage::retrieveData() {
	std::ifstream database("storage.txt");
	if (!database.is_open()) {
		throw "failed to load data from data base";
	}
	char buffer[1024];
	while (!database.eof()) {
		database.getline(buffer, 1024);
		int i = 0;
		while (buffer[i] !='\0') {
			std::cout << buffer[i++];
		}
		std::cout << std::endl;
	}

}
