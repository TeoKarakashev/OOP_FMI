#pragma once
#include "IngredientsNames.h"
#pragma warning(disable: 4996)
class Dish {

	IngredientName ingredientsNames[100];
	unsigned ingredientsNamesCounter;
	unsigned cookTime;
	
public:
	Dish();
	Dish(unsigned cookTime);
	Dish(const Dish& other) = default;
	virtual ~Dish() = default;
	void addIngredient(const IngredientName& name);
	void print() const;
	const unsigned getCookTime() const;
	virtual Dish* clone() const = 0;
};
