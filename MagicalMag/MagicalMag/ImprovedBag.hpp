#include "Bag.hpp";
#pragma warning(disable: 4996)
template<typename T>
class ImprovedBag : public Bag<T> {
	char* manifacturer;

	void free();
	void copyFrom(const ImprovedBag& other);
public:
	ImprovedBag();
	ImprovedBag(const char* manifactuter);
	ImprovedBag(const ImprovedBag& other);
	ImprovedBag<T>& operator=(const ImprovedBag& other);
	~ImprovedBag();

	bool insert(const T& el, int index);
};

template<typename T>
bool ImprovedBag<T>::insert(const T& el, int index) {
	return false;
}

template<typename T>
void ImprovedBag<T>::free() {
	delete[] manifacturer;
}

template<typename T>
inline void ImprovedBag<T>::copyFrom(const ImprovedBag& other) {
	manifacturer = new char[strlen(other.manifacturer) + 1];
	strcpy(manifacturer, other.manifacturer);
}

template<typename T>
inline ImprovedBag<T>::ImprovedBag(const char* manifactuter) {
	this->manifacturer = new char[strlen(manifactuter) + 1];
	strcpy(this->manifacturer, manifacturer);
}

template<typename T>
inline ImprovedBag<T>::ImprovedBag() {
	manifacturer = nullptr;
}


template<typename T>
ImprovedBag<T>::~ImprovedBag() {
	free();
}
template<typename T>
ImprovedBag<T>& ImprovedBag<T>::operator=(const ImprovedBag& other)
{
	if (this != &other) {
		free();
		copyFrom(other);
	}
	return *this;
}
template<typename T>
ImprovedBag<T>::ImprovedBag(const ImprovedBag& other) {
	copyFrom(other);
}


