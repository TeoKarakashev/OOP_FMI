#include "CarPart.h"

CarPart::CarPart() {
	id = "1";
	manifacturer = "Tesla";
	comment = "random useless";
}

CarPart::CarPart(const string& id, const string& manifacturer, const string& comment){
	this->id = id;
	this->manifacturer = manifacturer;
	this->comment = comment;
}

const string CarPart::getId() const
{
	return id;
}

const string CarPart::getManifactuter() const
{
	return manifacturer;
}

const string CarPart::getComment() const
{
	return comment;
}
