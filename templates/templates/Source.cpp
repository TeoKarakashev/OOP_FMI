#include <iostream>
#include "Stack.hpp"
#include "queue.hpp"
template <typename T>
void merge(T* arr1, int size1, T* arr2, int size2) {
	int newArrLength = size1 + size2;
	T* newArr = new T[newArrLength];
	int newArrIndex = 0;
	int firstIter = 0;
	int secondIter = 0;
	while (firstIter != size1 && secondIter != size2) {
		if (arr1[firstIter] < arr2[secondIter]) {
			newArr[newArrIndex++] = arr1[firstIter++];
		}
		else {
			newArr[newArrIndex++] = arr2[secondIter++];
		}
	}

	while (secondIter != size2) {
		newArr[newArrIndex++] = arr2[secondIter++];

	}

	while (firstIter != size1) {
		newArr[newArrIndex++] = arr1[firstIter++];
	}

	for (int i = 0; i < newArrLength; i++)
		arr1[i] = newArr[i];

	delete[] newArr;

}

template <typename T>
void mergeSort(T* arr, int size) {
	if (size == 1) {
		return;
	}
	int mid = size / 2;
	mergeSort<T>(arr, mid);
	mergeSort<T>(arr + mid, size - mid);
	merge<T>(arr, mid, arr + mid, size - mid);
}

int main() {

	/*int* arr = new int[10]{ 15, 19, 8 , 15, 7, 20, -2, 5, 9, 114 };
	mergeSort<int>(arr, 10);
	for (size_t i = 0; i < 10; i++) {
		std::cout << arr[i] << " ";
	}
	delete[] arr;*/

	//Stack<int> stack;
	//stack.push(15);
	//int a = 5;
	//stack.push(a);

	MyQueue<int> que;
	que.push(15);
	que.push(12);
	que.push(12);
}