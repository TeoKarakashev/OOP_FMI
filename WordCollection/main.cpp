#include <iostream>
#include "WordCollection.h"
int main() {
	
	WordCollection dict;
	(((dict *= "Ivan") *= "Petur") *= "Alex");
	std::cout << dict << std::endl; // {Alex, Ivan, Petur}
	std::cout << dict["Alex"] << " " << dict["abc"] << std::endl; // 1 0
	WordCollection dict2;
	((dict *= "Zebra") *= "Alex");

	WordCollection result = dict + dict2;
	std::cout << result << std::endl; // {Alex, Ivan, Petur, Zebra}

	//WordCollection result2 = dict - dict2;
	//std::cout << result2 << std::endl; // {Ivan, Petur}

	//result2 << "NewWOrd";
	//result2 \ = "NonExistingWord"
	//	std::cout << result2 << std::endl;  //{Ivan, NewWOrd, Petur}
	//std::cin >> result2; //въвеждаме "Job"
	//std::cout << result2 << std::endl;  //{Ivan, Job, NewWOrd, Petur}
}
