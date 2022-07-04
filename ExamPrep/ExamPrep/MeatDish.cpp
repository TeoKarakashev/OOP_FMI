#include "MeatDish.h"

void MeatDish::free() {
	delete[] meat;
}

void MeatDish::copyFrom(const MeatDish& other) {
	meat = new char[strlen(other.meat) + 1];
	strcpy(meat, other.meat);
}

MeatDish::MeatDish(const char* meat, unsigned cookTime) : Dish(cookTime) {
	this->meat = new char[strlen(meat) + 1];
	strcpy(this->meat, meat);
}

MeatDish::MeatDish(const MeatDish& other) : Dish(other) {
	copyFrom(other);
}

MeatDish& MeatDish::operator=(const MeatDish& other) {
	if (this != &other) {
		free();
		copyFrom(other);
	}

	return *this;
}

MeatDish::~MeatDish() {
	free();
}

Dish* MeatDish::clone() const {
	Dish* copy = new MeatDish(*this);
	return copy;
}

void MeatDish::print() const {
	Dish::print();
	std::cout << "Protein type: ";
	size_t size = strlen(meat);
	for (size_t i = 0; i < size; i++){
		std::cout << meat[i];
	}
}


