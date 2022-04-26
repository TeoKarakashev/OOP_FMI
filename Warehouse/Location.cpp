#include "Location.h"

Location::Location() {

}

Location::Location(char section, unsigned shelf, unsigned startPosition, unsigned endPosition) {
	this->section = section;
	this->shelf = shelf;
	this->startPosition = startPosition;
	this->endPosition = endPosition;
}
