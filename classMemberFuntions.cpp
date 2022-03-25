#include <iostream>
#include <fstream>
#include  <cstring>
#pragma warning(disable: 4996)
const int MAX_SIZE = 10;

void duplicate(const char* filePath, const char* destPath, int n) {
	std::ifstream inFile(filePath);
	std::ofstream outFile(destPath);
	char buffer[1024];
	for (size_t i = 0; i < n; i++) {
		while (!inFile.eof()) {
			inFile.getline(buffer, 1024);
			outFile << buffer;
		}
		inFile.seekg(0);
	}
}


class Exercise {
private:
	char* name = nullptr;
	char* task = nullptr;
	int points;

public:
	void setName(const char* name) {
		if (this->name != nullptr) {
			delete[] this->name;
		}
		this->name = new char[strlen(name)];
		strcpy(this->name, name);
	}

	void setTask(const char* task) {
		if (this->task != nullptr) {
			delete[] this->task;
		}
		this->task = new char[strlen(task)];
		strcpy(this->task, task);
	}

	const char* getTask() {
		return this->task;
	}

	void setPoints(const int points) {
		this->points = points;
	}

};

class Exam {
private:
	Exercise exercises[MAX_SIZE];
	int pointsToPass;
	int size;

public:

	Exam() {
		this->size = 0;
	}

	Exercise* getExercises() {
		return this->exercises;
	}

	void addExercise(Exercise exercise) {
		exercises[size++] = exercise;
	}

	int getSize() {
		return this->size;
	}

	void writeToFile(const char* destination, Exam exam) {
		std::ofstream outFile(destination, std::ios::binary);
		outFile.write((const char*)&exam, sizeof(exam));
	}

	void readFromFile(const char* location) {
		Exam currentEx;
		std::ifstream inFile(location, std::ios::binary);
		while (!inFile.eof()){
			inFile.read((char*)&currentEx, sizeof(Exercise));
			size_t size = currentEx.size;
			for (size_t i = 0; i < size; i++){
				std::cout << currentEx.getExercises()[i].getTask()<<std::endl;
			}
		}
	}

};

int main() {
	Exercise ex1;
	ex1.setName("ex1");
	ex1.setTask("neshto brat");
	ex1.setPoints(15);

	Exercise ex2;
	ex2.setName("ex2");
	ex2.setTask("neshto brat");
	ex2.setPoints(15);
	//std::cout << ex1.getTask();
	Exam exam;
	exam.addExercise(ex1);
	exam.addExercise(ex2);
	//std::cout << exam.getSize();
	//exam.writeToFile("result.txt", exam);
	exam.readFromFile("result.txt");
	//std::cout << ex1.getTask();
}