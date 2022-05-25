#include <iostream>

#include "Bag.hpp"

int main() {
	Bag<int> bag;
	Bag<int> bag2;
	bag.add(1);
	bag.add(2);
	bag.add(3);

	bag2.add(4);
	bag2.add(5);
	bag2.add(6);

	std::cout << (bag == bag2)<<std::endl;
	std::cout<<bag2.get()<<std::endl;
	std::cout << (bag == bag2)<<std::endl;
	Bag<int> newbag = bag + bag2;
	for (size_t i = 0; i < 5; i++){
		std::cout << newbag.get();
	}
}