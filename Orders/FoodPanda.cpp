#include "FoodPanda.h"

void FoodPanda::copyFrom(const FoodPanda& other) {
	restaurants = new Restaurant[other.size];
	for (int i = 0; i < other.size; i++){
		restaurants[i] = other.restaurants[i];
	}
	size = other.size;
}

void FoodPanda::free() {
	delete[] restaurants;
}

bool FoodPanda::contains(char* restaurant)
{
	for (int i = 0; i < size; i++){
		if (restaurants[i] == restaurant) {
			return true;
		}
	}
	return false;
}

void FoodPanda::resize() {
	capacity *= 2;
	Restaurant* temp = new Restaurant[capacity];
	for (int i = 0; i < size; i++) {
		temp[i] = restaurants[i];
	}
	free();
	restaurants = temp;
}

void FoodPanda::add(const Restaurant& restaurant) {
	if (size == capacity) {
		resize();
	}
	restaurants[size++] = restaurant;
}

FoodPanda::FoodPanda(){
	this->restaurants = new Restaurant[2];
	size = 0;
	capacity = 2;
}

FoodPanda::FoodPanda(const FoodPanda& other) {
	copyFrom(other);
}

FoodPanda& FoodPanda::operator=(const FoodPanda& other)
{
	if (this != &other) {
		free();
		copyFrom(other);
	}
	return *this;
}

FoodPanda::~FoodPanda() {
	free();
}

bool FoodPanda::order(const Order& order){
	if (contains(order.getRestaurantName())) {
		return true;
	}
	return false;
}
