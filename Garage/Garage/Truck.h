#pragma once
#include "Vehicle.h"
class Truck : public Vehicle {
public:
	Truck(const char* model, size_t maxVelo);
	void setModel(const char* model);
	void setVelocity(size_t maxVelocity);
	Vehicle* clone() const override;
	size_t getSpeedByRoad(const char* roadType) const override;
};