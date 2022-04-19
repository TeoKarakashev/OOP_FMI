#pragma once
#include "Product.h"
class Order {
	char* restaurant;
	Product* products;
	int size;
	int capacity;
	void free();
	void copyFrom(const Order& other);
	void resize();

public:
	Order();
	Order(char* name);
	Order(const Order& other);
	Order& operator=(const Order& other);
	~Order();
	char* getRestaurantName() const;
	Product* getProdcuts() const;
	void addProduct(const Product& product);
};
