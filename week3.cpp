#include <iostream>
#include <fstream>

const int MAX_SIZE = 25;

#pragma warning(disable: 4996)
struct JobOffer {
	char companyName[MAX_SIZE];
	int countCoWorkers;
	int freeDays;
	long long salary;
};


void save(JobOffer& jobOffer) {
	std::ofstream outFile("output.txt", std::ios::binary | std::ios::app);
	outFile.write((const char*)&jobOffer, sizeof(JobOffer));

}

int getOffersCountInFile(const char* filePath) {
	int count = 0;
	std::ifstream inFile(filePath, std::ios::binary);
	char* buffer[1024];
	while (!inFile.eof()) {
		inFile.read((char*)&buffer, sizeof(JobOffer));
		count++;
	}
	return count - 1;
}



void printOffers(const JobOffer* offers, int size) {
	for (size_t i = 0; i < size; i++){
		std::cout << "Company name:" << offers[i].companyName << std::endl;
		std::cout << "Count CoWorkers:" << offers[i].countCoWorkers << std::endl;
		std::cout << "FreeDays:" << offers[i].freeDays << std::endl;
		std::cout << "Offer salary:" << offers[i].salary << std::endl;
	}
}

void filterOffers(const char* filePath, long long minSalary) {
	std::ifstream inFile(filePath, std::ios::binary);
	int count = getOffersCountInFile(filePath);
	size_t index = 0;
	JobOffer* goodOffers = new JobOffer[count];
	JobOffer currentOffer;
	for (size_t i = 0; i < count; i++) {
		inFile.read((char*)&currentOffer, sizeof(JobOffer));
		if (currentOffer.salary >= minSalary) {
			goodOffers[index++] = currentOffer;
		}
	}
	printOffers(goodOffers, index);

	delete[] goodOffers;
}

bool existOffers(const char* filePath, const char* companyName) {
	std::ifstream inFile(filePath, std::ios::binary);
	int count = getOffersCountInFile(filePath);
	size_t index = 0;
	JobOffer* goodOffers = new JobOffer[count];
	JobOffer currentOffer;
	for (size_t i = 0; i < count; i++) {
		inFile.read((char*)&currentOffer, sizeof(JobOffer));
		if (currentOffer.companyName == companyName) {
			return true;
		}
	}
	delete[] goodOffers;
	return false;

}


int main() {
	JobOffer j1;
	strcpy(j1.companyName, "companyName");
	j1.countCoWorkers = 5;
	j1.freeDays = 30;
	j1.salary = 1700;

	JobOffer j2;
	strcpy(j2.companyName, "companyName2");
	j2.countCoWorkers = 10;
	j2.freeDays = 25;
	j2.salary = 3100;

	//save(j1);
	//save(j2);
	//std::cout << getOffersCountInFile("output.txt");
	std::cout<<existOffers("output.txt", "companyName");
}