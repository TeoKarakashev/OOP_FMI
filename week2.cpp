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

	inFile.close();
}

int getFileSize(const char* fileName) {
	std::ifstream inFile(fileName);
	char line[1024];
	int count = 0;
	if (!inFile.is_open()) {
		std::cout << "no";
		return -1;
	}
	while (!inFile.eof())
	{
		inFile.getline(line, 1024);
		count += strlen(line) + 1;
	}
	count--;
	return count;

	inFile.close();
}

void writeInFile(const char* filename) {
	std::ofstream outFile(filename);
	if (!outFile.is_open()) {
		std::cout << "no";
		return;
	}

	int a, b, c;
	std::cin >> a>>b>>c;
	outFile << a * b * c << " " << a + b + c;

	outFile.close();
}

void getFileCode(const char* filename) {
	std::ifstream inFile(filename);
	char line[1024];
	if (!inFile.is_open()) {
		std::cout << "no";
		return;
	}
	while (!inFile.eof()){
		inFile.getline(line, 1024);
		std::cout << line << std::endl;
	}
	inFile.close();
}


struct pair {
	int first;
	int second;
};

pair makePair(int fst, int snd) {
	return { fst, snd };
}

void initPair(pair& arg, int fst, int snd) {
	arg.first = fst;
	arg.second = snd;
}

const int MAX_SIZE = 25;

struct relation {
	pair data[MAX_SIZE];
	int size = 0;
};

void addPair(relation& toAdd, const pair& p) {
	if (toAdd.size > MAX_SIZE - 1)
		return;
	toAdd.data[toAdd.size++] = makePair(p.first, p.second);
}

void addPair(relation& toAdd, int first, int second) {
	if (toAdd.size > MAX_SIZE - 1)
		return;
	toAdd.data[toAdd.size++] = makePair(first, second);
}

void writePair(const pair& p, std::ofstream& out) {
	out << p.first << " " << p.second << std::endl;
}

pair readPair(std::ifstream& in) {
	int first = 0;
	int second = 0;
	in >> first >> second;
	return makePair(first, second);
}

void writeRelation(const relation& r) {
	std::ofstream outFile("relation.txt");
	if (outFile.bad())
		return;

	outFile << r.size << std::endl;

	for (int i = 0; i < r.size; i++)
		writePair(r.data[i], outFile);

	outFile.close();
}

relation readRelation() {
	std::ifstream inFile("relation.txt");

	if (inFile.bad())
		throw std::exception("Problem with reading the file");

	// alternative to throw: return relation(); -> returns empty relation

	relation toReturn;
	int size = 0;
	inFile >> size;

	for (int i = 0; i < size; i++)
		addPair(toReturn, readPair(inFile));

	inFile.close();
	return toReturn;
}

void printPair(const pair& p) {
	std::cout << p.first << " " << p.second << std::endl;
}

void printRelation(const relation& r) {
	for (int i = 0; i < r.size; i++)
		printPair(r.data[i]);
}

int main() {
	relation example;
	// {{1, 2, 3, 4}, <}
	addPair(example, 1, 2);
	addPair(example, 1, 3);
	addPair(example, 1, 4);
	addPair(example, 2, 3);
	addPair(example, 2, 4);
	addPair(example, 3, 4);

	printRelation(example);
	std::cout << std::endl;
	writeRelation(example);
	printRelation(readRelation());
}