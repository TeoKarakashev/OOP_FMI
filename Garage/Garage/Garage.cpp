#include "Garage.h"

void Garage::free() {
	for (int i = 0; i < size; i++) {
		delete vehicles[i];
	}
	delete[] vehicles;
}

void Garage::copyFrom(const Garage& other) {
	vehicles = new Vehicle * [other.capacity];
	size = other.size;
	capacity = other.capacity;
	for (int i = 0; i < size; i++) {
		vehicles[i] = other.vehicles[i]->clone();
	}
}

void Garage::resize() {
	capacity *= 2;
	Vehicle** temp = new Vehicle * [capacity *= 2];
	for (size_t i = 0; i < size; i++)
		temp[i] = vehicles[i]; // !!не правим клониране
	delete[] vehicles;
	vehicles = temp;
}

Garage::Garage() {
	vehicles = new Vehicle * [2];
	capacity = 2;
	size = 0;
}

Garage::Garage(const Garage& other) {
	copyFrom(other);
}

Garage& Garage::operator=(const Garage& other) {
	if (this != &other) {
		free();
		copyFrom(other);
	}
	return *this;
}

Garage::~Garage() {
	free();
}

void Garage::addCar(const char* model, size_t maxVelocity) {
	Car* car = new Car(model, maxVelocity);
	addVehicle(car);
}

void Garage::addMinivan(const char* model, size_t maxVelocity) {
	Minivan* minivan = new Minivan(model, maxVelocity);
	addVehicle(minivan);
}

void Garage::addTruck(const char* model, size_t maxVelocity) {
	Truck* truck = new Truck(model, maxVelocity);
	addVehicle(truck);
}

int Garage::getCountOfVehiclesForTrip(int distanceInKm, const char* trackType, int timeInHours) const {
	int count = 0;
	for (int i = 0; i < size; i++){
		if (vehicles[i]->getSpeedByRoad(trackType) >= distanceInKm / timeInHours) {
			count++;
		}
	}
	return count;
}


void Garage::addVehicle(Vehicle* vehicle) {
	if (size == capacity) {
		resize();
	}
	vehicles[size++] = vehicle;
}
