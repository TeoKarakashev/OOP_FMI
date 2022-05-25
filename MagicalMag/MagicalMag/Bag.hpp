#include <iostream>
template<typename T>
class Bag {
	T* data;
	size_t size;
	size_t capacity;
	size_t top;

	void free();
	void copyFrom(const Bag& other);
	void resize();
public:
	Bag();
	Bag(const Bag& other);
	Bag<T>& operator=(const Bag& other);
	~Bag();

	bool add(const T& el);
	bool add(T&& el);
	T get();
	bool isEmpty();
	bool operator==(const Bag<T>& other) const;
	Bag<T> operator+(Bag<T>& other);
	Bag<T>& operator+=(Bag<T>& other);
};

template<typename T>
void Bag<T>::free() {
	delete[] data;
}

template<typename T>
void Bag<T>::copyFrom(const Bag& other) {
	data = new T[other.capacity];
	for (int i = 0; i < other.size; i++) {
		data[i] = other.data[i];
	}
	size = other.size;
	capacity = other.capacity;
	top = other.top;
}

template<typename T>
void Bag<T>::resize() {
	capacity *= 2;
	T* newData = new T[capacity];
	for (int i = 0; i < size; i++) {
		newData[i] = data[i];
	}
	delete[] data;
	data = newData;
}

template<typename T>
Bag<T>::Bag() {
	data = new T[2];
	size = 0;
	capacity = 2;
	top = 0;
}

template<typename T>
Bag<T>::Bag(const Bag& other) {
	copyFrom(other);
}

template<typename T>
Bag<T>& Bag<T>::operator=(const Bag& other) {
	if (this != &other) {
		free();
		copyFrom(other);
	}
	return *this;
}

template<typename T>
Bag<T>::~Bag() {
	free();
}

template<typename T>
bool Bag<T>::add(const T& el) {
	if (size == capacity) {
		resize();
	}
	data[size++] = el;
	top = size - 1;
	return true;
}

template<typename T>
bool Bag<T>::add(T&& el) {
	if (size == capacity) {
		resize();
	}
	data[size++] = std::move(el);
	top = size - 1;
	return true;
}

template<typename T>
T Bag<T>::get() {
	if (isEmpty()) {
		throw "bag is empty";
	}
	T el = data[top];
	top--;
	size--;
	return el;
}

template<typename T>
bool Bag<T>::isEmpty() {
	return size == 0;
}

template<typename T>
bool Bag<T>::operator==(const Bag<T>& other) const {
	if (size != other.size) {
		return false;
	}
	for (int i = 0; i < size; i++){
		if (data[i] != other.data[i]) {
			return false;
		}
	}
	return true;
}

template<typename T>
Bag<T> Bag<T>::operator+(Bag<T>& other) {
	Bag<T> result(*this);
	result += other;
	return result;
}

template<typename T>
Bag<T>& Bag<T>::operator+=(Bag<T>& other) {
	int sizeT = other.size;
	for (int i = 0; i < sizeT; i++) {
		add(other.get());
	}
	return *this;
}


