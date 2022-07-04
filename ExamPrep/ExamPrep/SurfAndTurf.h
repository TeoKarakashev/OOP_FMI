#pragma once
#include "Dish.h"
class SurfAndTurf {

	Dish** dishes;
	size_t capacity;
	size_t size;

	void free();
	void copyFrom(const SurfAndTurf& other);
	void resize();

public:
	SurfAndTurf();
	SurfAndTurf& operator=(const SurfAndTurf& other);
	SurfAndTurf(const SurfAndTurf& other);
	~SurfAndTurf();

	void addDish(const Dish* dish);

	void printAll() const;
};
