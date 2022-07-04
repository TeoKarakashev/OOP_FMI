#pragma once
#include <iostream>
class IngredientName {
	
	char* name;

	void free();
	void copyFrom(const IngredientName& other);

public:

	IngredientName();
	IngredientName(const char* name);
	IngredientName(const IngredientName& other);
	IngredientName& operator=(const IngredientName& other);
	~IngredientName();

	const char* getName() const;
};
