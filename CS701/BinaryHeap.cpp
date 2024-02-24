#include "BinaryHeap.h"

template<class ElementType>
BinaryHeap<ElementType>::BinaryHeap(ElementType* array, size_t sizeOfArray) {
	data = array;
	SIZE = sizeOfArray;

	std::cout << "In class pointer is " << data << std::endl;
}

