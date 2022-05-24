#pragma once
#include<iostream>
#pragma warning(disable: 4996)
class Vehicle {
	char* model;
	size_t maxVelocity;

	void free();
	void copyFrom(const Vehicle& other);
public:
	Vehicle();
	Vehicle(const char* model, size_t maxVelo);
	Vehicle(const Vehicle& other);
	Vehicle& operator=(const Vehicle& other);
	virtual ~Vehicle();
	void setModel(const char* model);
	void setVelocity(size_t velocity);
	virtual Vehicle* clone() const = 0;
	virtual size_t getSpeedByRoad(const char* roadType) const = 0;
	const size_t getMaxVelocity() const;
};
