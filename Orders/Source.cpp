#include <iostream>

int closest(int v) {
	v--;
	v |= v >> 1;
	v |= v >> 2;
	v |= v >> 4;
	v |= v >> 8;
	v |= v >> 16;
	v++;
	return v;
}

int main() {
	std::cout << closest(5)<<std::endl;
	std::cout << closest(4) << std::endl;
	std::cout << closest(7) << std::endl;
	std::cout << closest( 255) << std::endl;
}