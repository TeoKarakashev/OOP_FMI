#pragma once

class Location {
	char section;
	unsigned shelf;
	unsigned startPosition;
	unsigned endPosition;

public:
	Location();
	Location(char section, unsigned shelf, unsigned startPosition, unsigned endPosition);
};
