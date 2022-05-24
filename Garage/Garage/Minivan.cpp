#include "Minivan.h"

Minivan::Minivan(const char* model, size_t maxVelo) {
	setModel(model);
	setVelocity(maxVelo);
}

void Minivan::setModel(const char* model) {
	Vehicle::setModel(model);
}

void Minivan::setVelocity(size_t maxVelocity) {
	if (maxVelocity >= 120 && maxVelocity <= 160) {
		Vehicle::setVelocity(maxVelocity);
	}
	else {
		throw "invalid data";
	}
}

Vehicle* Minivan::clone() const
{
	Vehicle* copy = new Minivan(*this);
	return copy;
}

size_t Minivan::getSpeedByRoad(const char* roadType) const {
	if (strcmp(roadType, "highway") == 0) {
		return this->getMaxVelocity();
	}
	else if (strcmp(roadType, "speed road") == 0) {
		return this->getMaxVelocity() / 2;
	}
	else if (strcmp(roadType, "bad road") == 0) {
		return this->getMaxVelocity() / 3;
	}
	throw "no such road";
}
