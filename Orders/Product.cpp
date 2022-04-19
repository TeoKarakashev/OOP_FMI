#include "Product.h"
#include <iostream>
#include "Product.h"
#pragma warning(disable: 4996)
void Product::free(){
	delete[] name;
}
void Product::copyFrom(const Product& other){
	name = new char[strlen(other.name) + 1];
	strcpy(name, other.name);

}
Product::Product() {
}
Product::Product(const char* name){
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
}

Product::Product(const Product& other) {
	copyFrom(other);
}

Product& Product::operator=(const Product& other)
{
	if (this != &other) {
		free();
		copyFrom(other);
	}
	return *this;
}

Product::~Product() {
	free();
}
