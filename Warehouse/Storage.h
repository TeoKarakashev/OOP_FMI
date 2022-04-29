#pragma once
#include "Product.h"

class Storage {
	Product* products;
	size_t size;
	size_t capacity;
	friend class Controller;

	void copyFrom(const Storage& other);
	void free();
	void resize();
	Product	parse(const MyString& str);
	int* findAllDelimeters(const MyString& str, int*& arr);

public:
	Storage();
	Storage(const Storage& other);
	Storage& operator=(const Storage& other);
	~Storage();

	void add(const Product& product);
	void retrieveData();

	friend std::ostream& operator<<(std::ostream& stream, const Storage& products);
};