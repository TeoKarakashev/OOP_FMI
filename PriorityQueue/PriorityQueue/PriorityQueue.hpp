#include <iostream>
#include <exception>
#include "Queue.hpp"
template <typename T>
class PriorityQueue {
	MyQueue<T>* data;
	size_t priorities;

	void free();
	void copyFrom(const PriorityQueue<T>& other);

public:
	PriorityQueue();
	PriorityQueue(const size_t& priorities);
	PriorityQueue(const PriorityQueue<T>& other);
	PriorityQueue<T>& operator=(const PriorityQueue<T>& other);

	void push(const T& obj, const size_t& priority);
	void push(T&& obj, const size_t& priority); //позволява и местене
	void pop();

	const T& peek() const;
	~PriorityQueue();
};

template<typename T>
void PriorityQueue<T>::free() {
	delete[] data;
}

template<typename T>
void PriorityQueue<T>::copyFrom(const PriorityQueue<T>& other) {
	data = new MyQueue[other.priorities];
	for (int i = 0; i < other.priorities; i++) {
		this->data[i] = other.data[i];
	}
	this->priorities = other.priorities;
}

template<typename T>
PriorityQueue<T>::PriorityQueue() {
	data = new MyQueue<T>[1];
	priorities = 1;
}

template<typename T>
PriorityQueue<T>::PriorityQueue(const size_t& priorities) {
	data = new MyQueue<T>[priorities];
	this->priorities = priorities;
}

template<typename T>
PriorityQueue<T>::PriorityQueue(const PriorityQueue<T>& other) {
	copyFrom(other);
}

template<typename T>
PriorityQueue<T>& PriorityQueue<T>::operator=(const PriorityQueue<T>& other) {
	if (this != &other) {
		free();
		copyFrom(other);
	}
	return *this;
}

template<typename T>
void PriorityQueue<T>::push(const T& obj, const size_t& priority) {
	if (priority > priorities - 1) {
		throw std::logic_error("No such priority!");
	}
	data[priority].push(obj);
}

template<typename T>
void PriorityQueue<T>::push(T&& obj, const size_t& priority) {
	if (priority > priorities - 1) {
		throw std::logic_error("No such priority!");
	}
	data[priority].push(std::move(obj));
}

template<typename T>
void PriorityQueue<T>::pop() {
	for (int i = 1; i <= priorities; i++) {
		if (!data[priorities - i].isEmpty()) {
			data[priorities - i].pop();
			return;
		}
	}
	throw std::logic_error("Empty queue!");
}

template<typename T>
const T& PriorityQueue<T>::peek() const {
	for (int i = 1; i <= priorities; i++) {
		if (!data[priorities - i].isEmpty()) {
			return data[priorities - i].peek();
		}
	}
	throw std::logic_error("Empty queue!");
}

template<typename T>
PriorityQueue<T>::~PriorityQueue() {
	free();
}
