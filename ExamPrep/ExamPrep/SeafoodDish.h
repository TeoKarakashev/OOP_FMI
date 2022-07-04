#pragma once
#include "Dish.h"
class SeaFoodDish : public Dish {

	char* seafood;

	void free();
	void copyFrom(const SeaFoodDish& other);

public:

	SeaFoodDish(const char* seafood, unsigned cookTime);
	SeaFoodDish(const SeaFoodDish& other);
	SeaFoodDish& operator=(const SeaFoodDish& other);
	~SeaFoodDish();

	Dish* clone() const override;
	void print() const;
};
