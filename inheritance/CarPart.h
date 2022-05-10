#pragma once
#include "MyString.h"

class CarPart {
	string id;
	string manifacturer;
	string comment;

public:
	CarPart();
	CarPart(const string& id,const string& manifacturer,const string& comment);

	const string getId() const;
	const string getManifactuter() const;
	const string getComment() const;
};