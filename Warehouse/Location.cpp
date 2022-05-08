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

const char Location::getSection() const {
	return section;
}

const unsigned Location::getShelf() const {
	return shelf;
}

const unsigned Location::getStartPosition() const {
	return startPosition;
}

const unsigned Location::getEndPosition() const {
	return endPosition;
}

void Location::setEndPosition(unsigned endPosition) {
	this->endPosition = endPosition;
}

std::ostream& operator<<(std::ostream& stream, const Location& location) {
	stream << location.section << location.shelf << location.startPosition << location.endPosition;
	return stream;
}
