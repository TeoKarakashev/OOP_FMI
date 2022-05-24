#include "Car.h"

Car::Car(const char* model, size_t maxVelo) {
	setModel(model);
	setVelocity(maxVelo);
}

void Car::setModel(const char* model) {
	Vehicle::setModel(model);
}

void Car::setVelocity(size_t maxVelocity) {
	if (maxVelocity >= 180 && maxVelocity <= 240) {
		Vehicle::setVelocity(maxVelocity);
	}
	else {
		throw "invalid data";
	}
}

Vehicle* Car::clone() const{
	Vehicle* copy = new Car(*this);
	return copy;
}

size_t Car::getSpeedByRoad(const char* road) const
{
	return this->getMaxVelocity();
}
