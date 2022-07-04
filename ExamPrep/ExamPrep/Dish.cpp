#include "Dish.h"

Dish::Dish() {
	cookTime = 0;
	ingredientsNamesCounter = 0;
}

Dish::Dish(unsigned cookTime) {
	this->cookTime = cookTime;
	ingredientsNamesCounter = 0;
}


void Dish::addIngredient(const IngredientName& name) {
	ingredientsNames[ingredientsNamesCounter++] = name;
}

void Dish::print() const {
	std::cout << "This Dish requries:" << std::endl;
	for (size_t i = 0; i < ingredientsNamesCounter; i++){
		std::cout << i + 1 << ". " << ingredientsNames[i].getName() << std::endl;
	}
	std::cout << "required time: " << cookTime << std::endl;
}

const unsigned Dish::getCookTime() const {

	return 0;
}
