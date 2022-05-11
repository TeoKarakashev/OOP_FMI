#pragma once
#include "CarPart.h"
#include "MyString.h"
class Batery : public CarPart {
	string bateryId;
	unsigned short capacity;

public:
	Batery();
	Batery(const string& id, const string& manifactuter, const string& comment,const string& bateryId, unsigned short capacity);


};
