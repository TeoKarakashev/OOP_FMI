#include "SeafoodDish.h"

void SeaFoodDish::free() {
	delete[] seafood;
}

void SeaFoodDish::copyFrom(const SeaFoodDish& other) {
	seafood = new char[strlen(other.seafood) + 1];
	strcpy(seafood, other.seafood);
}

SeaFoodDish::SeaFoodDish(const char* meat, unsigned cookTime) : Dish(cookTime) {
	this->seafood = new char[strlen(meat) + 1];
	strcpy(this->seafood, meat);
}

SeaFoodDish::SeaFoodDish(const SeaFoodDish& other) : Dish(other) {
	copyFrom(other);
}

SeaFoodDish& SeaFoodDish::operator=(const SeaFoodDish& other) {
	if (this != &other) {
		free();
		copyFrom(other);
	}

	return *this;
}

SeaFoodDish::~SeaFoodDish() {
	free();
}

Dish* SeaFoodDish::clone() const {
	Dish* copy = new SeaFoodDish(*this);
	return copy;
}

void SeaFoodDish::print() const {
	SeaFoodDish::print();
	std::cout << "Protein type: ";
	size_t size = strlen(seafood);
	for (size_t i = 0; i < size; i++) {
		std::cout << seafood[i];
	}
}
