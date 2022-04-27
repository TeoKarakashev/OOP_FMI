#include "Location.h"

Location::Location() {
	section = '-';
	shelf = 0;
	startPosition = 0;
	endPosition = 0;
}

Location::Location(char section, unsigned shelf, unsigned startPosition, unsigned endPosition) {
	this->section = section;
	this->shelf = shelf;
	this->startPosition = startPosition;
	this->endPosition = endPosition;
}
