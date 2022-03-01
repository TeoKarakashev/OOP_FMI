#include <fstream>
#include <iostream>

void readFromFile(const char* fileName) {
	std::ifstream inFile(fileName);
	if (!inFile.is_open()) {
		std::cout << "no";
		return;
	}
	int product;
		int sum;
		inFile >> product;
		inFile >> sum;
		std::cout << product - sum;

}

int getFileSize(const char* fileName) {
	std::ifstream inFile(fileName);
	char line[1024];
	int count = 0;
	if (!inFile.is_open()) {
		std::cout << "no";
		return - 1;
	}
	while (!inFile.eof())
	{
		inFile.getline(line, 1024);
		count += strlen(line) + 1;
	}
	count--;
	return count;
}


int main  () {



	std::cout<<getFileSize("result.txt");

}