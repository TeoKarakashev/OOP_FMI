#include <iostream>
#include "NaturalNumbers.h"
#pragma warning (disable: 4996)
int main() {
	int nums[2];
	int nums2[2];
	nums[0] = 15;
	nums[1] = 20;
	nums2[0] = 10;
	nums2[1] = 15;
	NaturalNumbers nats(nums, 2, "set1");
	NaturalNumbers nats2(nums2, 2, "set2");
	NaturalNumbers nats3;
	nats3 = nats + nats2;
	nats += nats2;
	std::cout << nats;
	std::cout << nats2;
	std::cout << nats3;
	std::cout << nats[10]<<" "<< nats[1000]<<std::endl;

}