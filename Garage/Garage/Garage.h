#pragma once
#include "Vehicle.h"
#include "Car.h"
#include "Truck.h"
#include "Minivan.h"
class Garage {
	Vehicle** vehicles;
	size_t size;
	size_t capacity;

	void free();
	void copyFrom(const Garage& other);
	void resize();
	void addVehicle(Vehicle* vehicle);
public:
	Garage();
	Garage(const Garage& other);
	Garage& operator=(const Garage& other);
	~Garage();

	void addCar(const char* model, size_t maxVelocity);
	void addMinivan(const char* model, size_t maxVelocity);
	void addTruck(const char* model, size_t maxVelocity);

	int getCountOfVehiclesForTrip(int distance, const char* trackType, int time) const;
};
