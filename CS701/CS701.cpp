/*
CS701.cpp : This file contains the 'main' function.
Program execution begins and ends there.
*/
#include "BinaryHeap.h"
#

int main() {

	int array[10] = { 4, 1, 3 ,2, 16, 9, 10, 14, 8, 7};
	size_t sizeofArray = std::size(array);

	BinaryHeap<int> Heap(array, sizeofArray);
	//Heap.Sort();

	for (int i = 0; i < sizeofArray; i++) {
		std::cout << array[i] << " ";
	}
}