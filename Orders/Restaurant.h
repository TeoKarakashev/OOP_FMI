#pragma once
#include "Product.h"

class Restaurant{
	char name[25];
	Product* products;
	int productCount;
	int productCapacity;

	void free();
	void copyFrom(const Restaurant& other);
	void resize();
	int closest(int v);
public:
	Restaurant();
	void add(const Product& product);
	Restaurant(char* name);
	Restaurant(const Restaurant& other);
	Restaurant& operator=(const Restaurant& other);
	~Restaurant();
	bool operator==(const Restaurant& other);
};


