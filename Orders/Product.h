#pragma once

class Product {
	char* name;

	void free();
	void copyFrom(const Product& other);

public:
	Product();
	Product(const char* name);
	Product(const Product& other);
	Product& operator=(const Product& other);
	~Product();
};