#include <iostream>

struct ImaginaryNumber {
	double realPart;
	double imaginaryPart;
};

void printImaginaryNumber(const ImaginaryNumber& number) {
	std::cout << number.realPart << " + " << number.imaginaryPart << "i"<<std::endl;
}

ImaginaryNumber sumComplexNumbers(const  ImaginaryNumber& num1, const ImaginaryNumber& num2) {
	ImaginaryNumber result;
	result.realPart = num1.realPart + num2.realPart;
	result.imaginaryPart = num1.imaginaryPart + num2.imaginaryPart;
	return result;
}

struct Student {
	int facNumber;
	int year;
	double grade;
};

int digitsCount(int number) {
	int count = 0;
	while (number >0){
		number /= 10;
		count++;
	}

	return count;
}

void initStudent(Student& student) {
	//wrapper function
	int studentNumber;
	int studentYear;
	double studentGrade;
	std::cin >> studentNumber >> studentYear >> studentGrade;
	//
	if (digitsCount(studentNumber) == 5) {
		student.facNumber = studentNumber;
	}
	else {
		student.facNumber = 11111;
	}

	if (studentYear < 5) {
		student.year = studentYear;
	}
	else {
		student.year = 1;
	}
	
	if (studentGrade <= 6.00) {
		student.grade = studentGrade;
	}
	else {
		student.grade = 2.00;
	}
}

void printStudent(const Student& student) {
	std::cout << "facNumber:" << student.facNumber << std::endl;
	std::cout << "Year:" << student.year << std::endl;
	std::cout << "Grade:" << student.grade << std::endl;
}

const int N = 5;

struct Group {
	Student students[N] = { { 12345, 1, 3.00 }, { 12346, 1, 4.50 }, { 12347, 1, 6.00 } , { 12348, 1, 5.50 }, { 12349, 1, 5.00 } };
	double averageScore;
};

int countWhoGetsScolarship(const Group& group, double gradeToPass) {
	int count = 0;
	for (int i = 0; i < N; i++){
		if (group.students[i].grade >= gradeToPass) {
			count++;
		}
	}
	return count;
}


double getAverageScore(Group& group) {
	double sumOfGrades = 0;
	for (int i = 0; i < N; i++){
		sumOfGrades += group.students[i].grade;
	}

	group.averageScore = sumOfGrades / N;
	return sumOfGrades / N;

}

void swap(Student & a, Student& b)
{
	Student temp = a;
	a = b;
	b = temp;
}

void printScolarshipers(const Group& group, double gradeToPass) {
	Student studentsWithGoodGrade[N];
	int index = 0;
	for (int i = 0; i < N; i++) {
		if (group.students[i].grade >= gradeToPass) {
			studentsWithGoodGrade[index++] = group.students[i];
		}
	}
	for (int i = 0; i < index - 1; i++)
	{
		
		int minElementIndex = i;
		for (int j = i + 1; j < index; j++)
		{
			if (studentsWithGoodGrade[j].grade < studentsWithGoodGrade[minElementIndex].grade)
				minElementIndex = j;
		}
		if (minElementIndex != i)
			swap(studentsWithGoodGrade[i], studentsWithGoodGrade[minElementIndex]);
	}

	for (int i = 0; i < index; i++){
		printStudent(studentsWithGoodGrade[i]);
	}

}


int main() {

	Group group;
	printScolarshipers(group, 5.00);
}