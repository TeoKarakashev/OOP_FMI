#include "Order.h"
#include <iostream>
#pragma warning(disable: 4996)

void Order::free() {
	delete[] restaurant;
	delete[] products;
}

void Order::copyFrom(const Order& other) {
	restaurant = new char[strlen(other.restaurant) + 1];
	strcpy(restaurant, other.restaurant);
	products = new Product[other.size];
	for (int i = 0; i < other.size; i++) {
		products[i] = other.products[i];
	}
	size = other.size;
}

void Order::resize() {
	capacity *= 2;;
	Product* temp = new Product[capacity];
	for (int i = 0; i < size; i++) {
		temp[i] = products[i];
	}
	char* tempName = new char[strlen(restaurant) + 1];
	free();
	products = temp;
	restaurant = tempName;
}

Order::Order(){
	restaurant = nullptr;
	products = new Product[2];
	size = 0;
	capacity = 2;
}

Order::Order(char* name) {
	restaurant = new char[strlen(name) + 1];
	strcpy(restaurant, name);
	products = new Product[2];
	size = 0;
	capacity = 2;
}

Order::Order(const Order& other){
	copyFrom(other);
}

Order& Order::operator=(const Order& other)
{
	if (this != &other) {
		free();
		copyFrom(other);
	}
	return *this;
}

Order::~Order() {
	free();
}

char* Order::getRestaurantName() const
{
	return restaurant;
}

Product* Order::getProdcuts() const
{
	return products;
}

void Order::addProduct(const Product& product) {
	if (size == capacity) {
		resize();
	}
	products[size++] = product;
}
