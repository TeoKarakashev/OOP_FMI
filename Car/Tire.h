#pragma once
#include "CarPart.h"
class Tire : public CarPart {
	unsigned short width;
	unsigned short profile;
	unsigned short diameter;

public:
	Tire();
	Tire(const string& id, const string& manifacturer, const string& comment, unsigned short width, unsigned short profile, unsigned short diameter);

	const unsigned short getWidth() const;
	const unsigned short getProfile() const;
	const unsigned short getDiameter() const;
};
