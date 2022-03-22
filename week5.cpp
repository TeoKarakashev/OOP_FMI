#include <iostream>

#pragma warning(disable : 4996)

class Teacher {
	char* name;
	size_t age;
	size_t internship;

public:

	Teacher();
	Teacher(char* name);
	Teacher(char* name, size_t age, size_t intership);

	void setName(char* name) ;
	void setAge(size_t age) ;
	void setIntership(size_t intership) ;

	const char* getName() const;
	const size_t getAge() const;
	const size_t getIntership() const;

	~Teacher();
};

void Teacher::setAge(size_t age)  {
	this->age = age;
}

void Teacher::setIntership(size_t internship) {
	this->internship = internship;
}

void Teacher::setName(char* name)  {
	
	if (this->name != nullptr) {
		delete[] this->name;
	}
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
}

const char* Teacher::getName() const {
	return this->name;
}

const size_t Teacher::getAge() const {
	return this->age;
}

const size_t Teacher::getIntership() const {
	return this->internship;
}

Teacher::Teacher() {
	this->setName(nullptr) ;
	this->setAge(30);
	this->setIntership(5);
}

Teacher::Teacher(char* name) {
	this->name = nullptr;
	this->setName(name);
}

Teacher::Teacher(char* name, size_t age, size_t intership) {
	this->name = nullptr;
	this->setName(name);
	this->setAge(age);
	this->setIntership(intership);
}

Teacher::~Teacher() {
	delete[] this->name;
}


class Interval {

	double a;
	double b;


	int compare(double a, double b) {
		if (a < b) {
			return -1;
		}
		if (a > b) {
			return 1;
		}
		return 0;
	}

	bool isPrime(int n) {
		if (n <= 1) {
			return false;
		}
		int sqrtOfNum = sqrt(n);
		for (int i = 2; i <= sqrtOfNum; i++) {
			if (n % i == 0) {
				return false;
			}
		}
		return true;
	}

	int reverse(int n)
	{
		unsigned int result = 0;

		while (n != 0)
		{
			int lastDigit = n % 10;
			(result *= 10) += lastDigit;
			n /= 10;
		}

		return result;
	}

	bool isPalindrome( int n)
	{
		return n == reverse(n);
	}

	bool hasDiffrentDigits(int n) {
		bool arr[10];
		while (n > 0) {
			int currentNumber = n % 10;
			if (arr[currentNumber] == 1) {
				return false;
			}
			arr[currentNumber] = 1;
			n /= 10;
		}
		return true;
	}

public:
	
	Interval() {
		this->a = 0;
		this->b = 0;
	}

	Interval(double a, double b) {
		if (compare(a, b) != 1) {
			this->setA(a);
			this->setB(b);
		 }
		else {
			this->setA(0);
			this->setB(0);
		}
	}

	void setA(double a) {
		this->a = a;
	}

	void setB(double b) {
		this->b = b;
	}

	double getSize() {
		return b - a;
	}

	int getCountOfPrimeNubersInInterval() {
		int count = 0;
		for (size_t i = this->a; i <= this->b; i++){
			if (isPrime(i)) {
				count++;
			}
		}
		return count;
	}

	int getCountOfPalindormesInInterval() {
		int count = 0;
		for (size_t i = this->a; i <= this->b; i++) {
			if (isPalindrome(i)) {
				count++;
			}
		}
		return count;
	}

	int getCountOfNumbersWithDiffrentDigits() {
		int count = 0;
		for (size_t i = this->a; i <= this->b; i++) {
			if (hasDiffrentDigits(i)) {
				count++;
			}
		}
		return count;
	}
};

int main() {
	Interval interval(10, 20);
	std::cout<<interval.getCountOfNumbersWithDiffrentDigits();

}