#include <iostream>

class Interval {

	int a;
	int b;

	int compare(int a, int b) const {
		if (a < b) {
			return -1;
		}
		if (a > b) {
			return 1;
		}
		return 0;
	}

	bool areNumbersValid(int a, int b) const  {
		return compare(a, b) != 1;
	}

	bool isPrime( int n) const {
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

	int reverse(int n) const 
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

	bool isPalindrome(int n) const
	{
		return n == reverse(n);
	}

	bool hasDiffrentDigits(int n) const {
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

	bool isPowerOf2(int n) const {
		while (n != 0) {
			if (n == 1 || n == -2) {
				return true;
			}
			if (n % 2 == 1 || n % 2 == -1) {
				return false;
			}
			n /= 2;
		}
		return false;
	}

	int max(int a, int b) const{
		if (a >= b) {
			return a;
		}
		return b;
	}

	int min(int a, int b) const {
		if (a >= b) {
			return b;
		}
		return a;
	}

public:

	Interval() {
		this->setA(0);
		this->setB(0);
	}

	Interval(int a, int b) {
		if (areNumbersValid(a, b)) {
			this->setA(a);
			this->setB(b);
		}
		else {
			this->setA(0);
			this->setB(0);
		}
	}

	int getA() const {
		return this->a;
	}

	int getB() const {
		return this->b;
	}

	void setA(int a) {
		this->a = a;
	}

	void setB(int b) {
		this->b = b;
	}

	int getSize() const {
		return b - a;
	}

	bool isInInterval(int n) const{
		return this->getA() <= n && this->getB() >= n;
	}

	int getCountOfPrimeNubers() const{
		int count = 0;
		for (size_t i = this->a; i <= this->b; i++) {
			if (isPrime(i)) {
				count++;
			}
		}
		return count;
	}

	int getCountOfPalindormes() const {
		int count = 0;
		for (size_t i = this->a; i <= this->b; i++) {
			if (isPalindrome(i)) {
				count++;
			}
		}
		return count;
	}

	int getCountOfNumbersWithDiffrentDigits() const {
		int count = 0;
		for (size_t i = this->a; i <= this->b; i++) {
			if (hasDiffrentDigits(i)) {
				count++;
			}
		}
		return count;
	}

	bool areEndsPowerOf2() const  {
		return isPowerOf2(this->a) && isPowerOf2(this->b);
	}

	Interval findIntersectionWith(const Interval& interval) const {
		if (this->getA() > interval.getB() || interval.getA() > this->getB()) {
			return Interval(0, 0);
		}
		else {
			int a = max(this->getA(), interval.getA());
			int b = min(this->getB(), interval.getB());
			return Interval(a, b);
		}
	}

	bool containsInterval(const Interval& interval) const {
		return interval.getA() >= this->getA() && interval.getB() <= this->getB();
	}
};


int main() {
	
}