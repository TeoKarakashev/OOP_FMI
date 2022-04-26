#pragma once
#include "Product.h"

class Storage {
	Product* products;
	size_t size;
	size_t capacity;

	void copyFrom(const Storage& other);
	void free();
	void resize();

public:
	Storage();
	Storage(const Storage& other);
	Storage& operator=(const Storage& other);
	~Storage();

	void add(const Product& product);
};