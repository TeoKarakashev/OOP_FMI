#include "IngredientsNames.h"
#pragma warning(disable: 4996)
void IngredientName::free() {
	delete[] name;
}

void IngredientName::copyFrom(const IngredientName& other) {
	if (other.name != nullptr) {
	name = new char[strlen(other.name) + 1];
	strcpy(name, other.name);
	}
}

IngredientName::IngredientName() {
	name = nullptr;
}

IngredientName::IngredientName(const char* name) {
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
}

IngredientName::IngredientName(const IngredientName& other) {
	copyFrom(other);
}

IngredientName& IngredientName::operator=(const IngredientName& other) {
	if (this != &other) {
		free();
		copyFrom(other);
	}

	return *this;
}

IngredientName::~IngredientName() {
	free();
}

const char* IngredientName::getName() const
{
	return name;
}


