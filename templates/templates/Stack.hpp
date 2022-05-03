template <typename T>
#include <exception>
class Stack {
		
	T* data;
	size_t size;
	size_t capacity;
	
	size_t top;

	void free();
	void copyFrom(const Stack<T>& other);
	void resize();

public:
	Stack();
	Stack(const Stack& other);
	Stack<T>& operator=(const Stack& other);
	~Stack();

	void push(const T& el);
	void push(T&& el); 
	const T& top() const;
	void pop();
	bool isEmpty();

};

template<typename T>
void Stack<T>::free() {
	delete[] data;
}
template<typename T>
void Stack<T>::copyFrom(const Stack<T>& other) {
	data = new T[other.capacity];
	for (int i = 0; i < other.size; i++) {
		data[i] = other.data[i];
	}
	size = other.size;
	capacity = other.capacity;
	top = other.top;
}

template<typename T>
void Stack<T>::resize() {
	capacity *= 2;
	T newData = new T[capacity];
	for (int i = 0; i < size; i++){
		newData[i] = data[i];
	}
	delete[] data;
	data = newData;
}

template<typename T>
Stack<T>::Stack() {
	capacity = 2;
	data = new T[capacity];
	size = 0;
	top = 0;
}

template<typename T>
Stack<T>::Stack(const Stack& other){
	copyFrom(other);
}

template<typename T>
Stack<T>& Stack<T>::operator=(const Stack& other){
	if (this != &other) {
		free();
		copyFrom(other);
	}
	return *this;
}

template<typename T>
Stack<T>::~Stack(){
	free();
}

template<typename T>
void Stack<T>::push(const T& el){
	std::cout << "el" << std::endl;
	if (capacity == size) {
		resize();
	}
	push[top++] = T;
	size++;
}

template<typename T>
void Stack<T>::push(T&& el){
	std::cout << "move" << std::endl;
	if (capacity == size) {
		resize();
	}
	push[top++] = T;
	size++;
}

template<typename T>
const T& Stack<T>::top() const{
		if (isEmpty()) {
			throw std::exception("Empty stack");
		}
		return data[top];
	}


template<typename T>
void Stack<T>::pop() {
	if (isEmpty()) {
		throw std::exception("Empty stack");
	}
	top--;
	size--;
}


template<typename T>
bool Stack<T>::isEmpty() {
	return size == 0;
}


