#include "SurfAndTurf.h"

void SurfAndTurf::free() {
	for (size_t i = 0; i < size; i++){
		delete dishes[i];
	}
	delete[] dishes;
}

void SurfAndTurf::copyFrom(const SurfAndTurf& other) {
	dishes = new Dish * [other.capacity];
	capacity = other.capacity;
	size = other.size;

	for (size_t i = 0; i < size; i++){
		dishes[i] = other.dishes[i]->clone();
	}
}

void SurfAndTurf::resize(){
	Dish** temp = new Dish * [capacity *= 2];
	for (size_t i = 0; i < size; i++){
		temp[i] = dishes[i];
	}
	delete[] dishes;
	dishes = temp;
}

SurfAndTurf::SurfAndTurf() {
	capacity = 2;
	size = 0;
	dishes = new Dish * [capacity];
}

SurfAndTurf& SurfAndTurf::operator=(const SurfAndTurf& other) {
	if (this != &other) {
		free();
		copyFrom(other);
	}
	return *this;
}

SurfAndTurf::SurfAndTurf(const SurfAndTurf& other) {
	copyFrom(other);
}

SurfAndTurf::~SurfAndTurf() {
	free();
}

void SurfAndTurf::addDish(const Dish* dish){
	if (size == capacity) {
		resize();
	}
	dishes[size++] = dish->clone();
}

void SurfAndTurf::printAll() const {
	for (size_t i = 0; i < size; i++){
		dishes[i]->print();
		std::cout << std::endl;
	}
}
