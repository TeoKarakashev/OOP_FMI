#include "Vehicle.h"

void Vehicle::free() {
	delete[] model;
}

void Vehicle::copyFrom(const Vehicle& other) {
	model = new char[strlen(other.model) + 1];
	strcpy(model, other.model);
	maxVelocity = other.maxVelocity;
}

Vehicle::Vehicle() {
	model = nullptr;
	maxVelocity = 0;
}

Vehicle::Vehicle(const char* model, size_t maxVelo) {
	this->model = new char[strlen(model) + 1];
	strcpy(this->model, model);
	maxVelocity = maxVelo;
}

Vehicle::Vehicle(const Vehicle& other) {
	copyFrom(other);
}

Vehicle& Vehicle::operator=(const Vehicle& other) {
	if (this != &other) {
		free();
		copyFrom(other);
	}
	return *this;
}

Vehicle::~Vehicle() {
	free();
}

void Vehicle::setModel(const char* model) {
	if (this->model != nullptr) {
		free();
	}
	this->model = new char[strlen(model) + 1];
	strcpy(this->model, model);
}

void Vehicle::setVelocity(size_t velocity) {
	maxVelocity = velocity;
}

const size_t Vehicle::getMaxVelocity() const
{
	return this->maxVelocity;
}
