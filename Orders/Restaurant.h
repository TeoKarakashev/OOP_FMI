#pragma once
#include "Product.h"

class Restaurant{
	char name[25];
	Product* products;
	size_t productCount;
	size_t productCapacity;

	void free();
	void copyFrom(const Restaurant& other);
	void resize();
	void add(const Product& product);
public:
	Restaurant(const Product* products, int size);
	Restaurant(const Restaurant& other);
	Restaurant& operator=(const Restaurant& other);
	~Restaurant();
};
