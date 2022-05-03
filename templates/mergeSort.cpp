#include <iostream>

template <typename T>
void merge(T* arr1, int size1, T* arr2, int size2) {
	T* newArr = new T[size1 + size2 + 1];
		int newArrIndex = 0;
		int firstIter = 0;
		int secIter = 0;
	while (firstIter != size1 && secIter != size2) {
		if (arr1[firstIter] < arr2[secIter]) {
			newArr[newArrIndex++] = arr1[firstIter++];
		}
		else {
			newArr[newArrIndex++] = arr2[secIter++];
		}
	}

	while (secIter != size2) {
		newArr[newArrIndex++] = arr2[secIter++];

	}

	while (firstIter != (size1)) {
		newArr[newArrIndex++] = arr1[firstIter++];
	}
	newArrIndex = 0;
	firstIter = 0;
	secIter = 0;
	while (firstIter <= size1) {
		arr1[firstIter++] = newArr[newArrIndex++];
	}
	while(secIter <= size2) {
		arr2[secIter++] = newArr[newArrIndex++];
	}
}

template <typename T>
void mergeSort(T* arr, int size) {
	if (size == 1) {
		return;
	}
	mergeSort<T>(arr, size / 2);
	mergeSort<T>(arr + size / 2 + 1, size - (size / 2) );
	merge<T>(arr, size / 2, arr + (size / 2) + 1, size - (size / 2));
}

int main() {

	int* arr = new int[6]{ 15, 19, 8 , 15, 7, 19 };
	mergeSort<int>(arr, 5);
	for (size_t i = 0; i < 6; i++) {
		std::cout << arr[i] << " ";
	}
	delete[] arr;
}
