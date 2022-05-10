#pragma once
#include "CarPart.h"

class Engine : public CarPart {
	unsigned short horsePower;

public:
	Engine();
	Engine(const string& id, const string& manifacturer, const string& comment, unsigned short horsePower);

	const unsigned short getHorsePower() const;
};
