#include "Storage.h"
#include "Product.h"
void Storage::copyFrom(const Storage& other) {
	products = new Product[other.capacity];
	for (int i = 0; i < other.size; i++){
		products[i] = other.products[i];
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
	for (int i = 0; i < size; i++){
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

Storage::Storage(const Storage& other){
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
