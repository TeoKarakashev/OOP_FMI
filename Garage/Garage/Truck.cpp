#include "Truck.h"

Truck::Truck(const char* model, size_t maxVelo) {
	setModel(model);
	setVelocity(maxVelo);
}


void Truck::setModel(const char* model) {
	Vehicle::setModel(model);
}

void Truck::setVelocity(size_t maxVelocity) {
	if (maxVelocity >= 80 && maxVelocity <= 140) {
		Vehicle::setVelocity(maxVelocity);
	}
	else {
	throw "invalid data";
	}
}

Vehicle* Truck::clone() const
{
	Vehicle* copy = new Truck(*this);
	return copy;
}

size_t Truck::getSpeedByRoad(const char* roadType) const{
	if (strcmp(roadType, "highway") == 0) {
		return this->getMaxVelocity() / 2;
	}
	else if (strcmp(roadType, "speed road") == 0) {
		return this->getMaxVelocity() / 4;
	}
	else if (strcmp(roadType, "bad road") == 0) {
		return 10;
	}
	throw "no such road";
}
