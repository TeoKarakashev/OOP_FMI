#include "Batery.h"


Batery::Batery() {
	bateryId = "0";
	capacity = 0;
}

Batery::Batery(const string& id, const string& manifactuter, const string& comment, const string& bateryId, unsigned short capacity) : CarPart(id, manifactuter, comment){
	this->bateryId = bateryId;
	this->capacity = capacity;
}
