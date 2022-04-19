#pragma once
#include "Restaurant.h"
#include "Order.h"
class FoodPanda {
	Restaurant* restaurants;
	int size;
	int capacity;

	void copyFrom(const FoodPanda& other);
	void free();
	bool contains(char* restaurant);
	void resize();
public:
	void add(const Restaurant& restaurant);
	FoodPanda();
	FoodPanda(const FoodPanda& other);
	FoodPanda& operator=(const FoodPanda& other);
	~FoodPanda();
	bool order(const Order& order);
};