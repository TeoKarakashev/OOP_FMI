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



Restaurant::Restaurant(const Product* prods, int size) {
	products = new Product[size];
	for (int i = 0; i < size; i++) {
		products[i] = prods[i];
	}
	strcpy(name, "Glovo");
	productCount = size;
	productCapacity = size + 1;

}
