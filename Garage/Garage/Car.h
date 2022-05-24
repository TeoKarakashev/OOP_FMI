#pragma once
#include "Vehicle.h"

class Car : public Vehicle {

public:

	Car(const char* model, size_t maxVelo);
	void setModel(const char* model);
	void setVelocity(size_t velocity);
	Vehicle* clone() const override;
	size_t getSpeedByRoad(const char* road) const override;
};