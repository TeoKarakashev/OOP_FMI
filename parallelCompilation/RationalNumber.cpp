#include "RationalNumber.h"
#include <iostream>




int RationalNumber::gcd(int n, int k)  {
	if ((n >= k) && ((n % k) == 0))
		return(k);
	else
		gcd(k, (n % k));
}

RationalNumber::RationalNumber() {
	setNumerator(0);
	setDenominator(0);
}

RationalNumber::RationalNumber(int numerator, int denominator) {
	setNumerator(numerator);
	setDenominator(denominator);
}

void RationalNumber::setNumerator(int numerator) {
	this->numerator = numerator;
}

void RationalNumber::setDenominator(int denominator) {
	if (denominator == 0) {
		denominator = 1;
	}
	this->denominator = denominator;
}

int RationalNumber::getDenominator() const{
	return denominator;
}

int RationalNumber::getNumerator() const {
	return numerator;
}

void RationalNumber::simplify() {
	int n = gcd(numerator, denominator);
	this->setDenominator(denominator / n);
	this->setNumerator(numerator / n);
}

void RationalNumber::add(const RationalNumber& arg) {
	int lcm = 0;
	if (denominator == arg.getDenominator()) {
		lcm = denominator;
	}
	else {
		lcm = denominator* arg.getDenominator();
	}
	numerator = (numerator * (lcm/ denominator)) + (arg.getNumerator() * (lcm/ arg.getDenominator()));
	denominator = (denominator * (lcm / denominator));
	simplify();
}

void RationalNumber::subtract(const RationalNumber& arg) {
	int lcm = 0;
	if (denominator == arg.getDenominator()) {
		lcm = denominator;
	}
	else {
		lcm = denominator * arg.getDenominator();
	}
	numerator = (numerator * (lcm / denominator)) - (arg.getNumerator() * (lcm / arg.getDenominator()));
	denominator = (denominator * (lcm / denominator));
	simplify();
}

void RationalNumber::multiply(const RationalNumber& arg) {
	numerator = (numerator *  arg.getNumerator());
	denominator = (denominator * arg.getDenominator());
	simplify();
}


void RationalNumber::print() const {
	std::cout << numerator << "/" << denominator;
}