#pragma once

class RationalNumber {
	int numerator;
	int denominator;


	int gcd(int n, int k);

public:
	RationalNumber();
	RationalNumber(int numerator, int denominator);

	int getNumerator() const;
	int getDenominator() const;

	void setNumerator(int numerator);
	void setDenominator(int denominator);

	void simplify();

	void add(const RationalNumber& arg) ;

	void subtract(const RationalNumber& arg) ;

	void multiply(const RationalNumber& arg) ;

	//void divide(const RationalNumber& arg) const;

	//int numcmp(const RationalNumber& arg) const;

	void print() const;

};
