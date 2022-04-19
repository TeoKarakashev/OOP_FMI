#include "Restaurant.h"
#include <iostream>
#pragma warning(disable: 4996)
void Restaurant::free() {
	delete[] products;
}

void Restaurant::copyFrom(const Restaurant& other) {
	strcpy(name, other.name);
	products = new Product[other.productCapacity];
	for (int i = 0; i < other.productCount; i++) {
		products[i] = other.products[i];
	}
	productCount = other.productCount;
	productCapacity = other.productCapacity;
}

void Restaurant::resize() {
	productCapacity *= 2;
	Product* temp = new Product[productCapacity];
	for (int i = 0; i < productCount; i++) {
		temp[i] = products[i];
	}
	free();
	products = temp;
}

int Restaurant::closest(int v)
{
	v--;
	v |= v >> 1;
	v |= v >> 2;
	v |= v >> 4;
	v |= v >> 8;
	v |= v >> 16;
	v++;
	return v;
}


Restaurant::Restaurant(){
	strcpy(name, "Unknown");
	products = new Product[2];
	productCount = 0;
	productCapacity = 2;
}

void Restaurant::add(const Product& product){
	if (productCount == productCapacity) {
		resize();
	}
	products[productCount++] = product;
}

Restaurant::Restaurant(char* name) {
	products = new Product[2];
	strcpy(name, this->name);
	productCount = 0;
	productCapacity = 2;
}

Restaurant::Restaurant(const Restaurant& other){
	copyFrom(other);
}

Restaurant& Restaurant::operator=(const Restaurant& other)
{
	if (this != &other) {
		free();
		copyFrom(other);
	}
	return *this;
}

Restaurant::~Restaurant(){
	free();
}

bool Restaurant::operator==(const Restaurant& other)
{
	return strcmp(name, other.name);
}
