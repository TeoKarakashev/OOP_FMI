#include "Tire.h"
Tire::Tire() {

}

Tire::Tire(const string& id, const string& manifacturer, const string& comment, unsigned short width, unsigned short profile, unsigned short diameter) : CarPart(id, manifacturer, comment){
	this->width = width;
	this->profile = profile;
	this->diameter = diameter;
}

const unsigned short Tire::getWidth() const
{
	return width;
}

const unsigned short Tire::getProfile() const
{
	return profile;
}

const unsigned short Tire::getDiameter() const
{
	return diameter;
}
