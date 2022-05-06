#include "Vector.h"

void Vector::resize()
{
	capacity *= 2;
	int* newArr = new int[capacity];
	for (size_t i = 0; i < size; i++)
	{
		newArr[i] = arr[i];
	}
	free();
	arr = newArr;
}

void Vector::free()
{
	delete[] arr;
}

void Vector::copyFrom(const Vector& other)
{
	size = other.size;
	capacity = other.capacity;
	arr = new int[capacity];
	for (int i = 0; i < size; i++)
	{
		arr[i] = other.arr[i];
	}
}

void Vector::swap(int& i1, int& i2){
	int temp = i2;
	i2 = i1;
	i1 = temp;
}

Vector::Vector()
{
	arr = new int[2];
	capacity = 2;
	size = 0;
}

Vector::Vector(const Vector& other)
{
	copyFrom(other);
}

Vector& Vector::operator=(const Vector& other)
{
	if (this != &other) {
		free();
		copyFrom(other);
	}
	return *this;
}

Vector::~Vector()
{
	free();
}

void Vector::push_back(const int element)
{
	if (size < capacity) {
		arr[size] = element;
		size++;
	}
	else
	{
		resize();
		push_back(element);
	}
}

int Vector::getSize() const
{
	return size;
}

int& Vector::operator[](const int index)
{
	if (index >= 0 && index < size) {
		return arr[index];
	}
	throw std::exception("Out of range exception");

}

const int& Vector::operator[](int index) const
{
	if (index >= 0 && index < size) {
		return arr[index];
	}
	throw std::exception("Out of range exception");
}

bool Vector::deleteAt(int index){
	if (index < 0 || index >= size)
		return false;
	for (int i = index; i < size - 1; i++){
		arr[i] = arr[i + 1];
	}
	size--;
	return true;
}

bool Vector::pop_back()
{
	return deleteAt(size-1);
}

int Vector::findItem(int el) const
{
	for (int i = 0; i < size; i++)
	{
		if (arr[i] == el) {
			return i;
		}
	}
	return -1;
}

void Vector::clear()
{
	free();
	arr = new int[2];
	capacity = 2;
	size = 0;
}

void Vector::sort(){
	for (int i = 0; i < size; i++){
		int minIndex = i;
		for (int j = i; j < size; j++){
			if (arr[j] < arr[minIndex]) {
				minIndex = j;
			}
		}
		swap(arr[i], arr[minIndex]);
	}
}

void Vector::print(std::ostream& stream) const{
	for (int i = 0; i < size; i++)
	{
		stream << arr[i];
	}
}

void Vector::reverse(){
	for (int i = 0; i < size/2; i++){
		swap(arr[i], arr[size - 1 - i]);
	}
	// åçèê å ðåãóë÷ðåí <=> {a^-1(L)|  e ot sigma*} e krajno
	// (à^n)^-1(L), ako k != n ---->
	// // neka L={a^nb^n|n e ot N}
	// a^nb^n e ot L => b^n e ot (a^n)^-1(L)
	// a^kb^n ne e ot L => b^n ne e ot (a^k)-1(l)
	//
}
