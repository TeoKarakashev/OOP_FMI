#include <iostream>
#include "RationalNumber.h"

int main() {
	RationalNumber k(5, 3);
	RationalNumber m(1, 5);
	k.multiply(m);
	k.print();
}
