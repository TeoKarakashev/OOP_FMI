#pragma once
#include "Dish.h"
class MeatDish: public  Dish{

	char* meat;

	void free();
	void copyFrom(const MeatDish& other);

public:

	MeatDish(const char* meat, unsigned cookTime);
	MeatDish(const MeatDish& other);
	MeatDish& operator=(const MeatDish& other);
	~MeatDish();

	Dish* clone() const override;
	void print() const;
};
