#pragma once

/*
1. to-do definition
2. fix index for 0, pseudo is for 1
*/

#include <iostream>

template <class ElementType>
class BinaryHeap {
public:
	BinaryHeap(ElementType* array, size_t sizeOfArray);
	void Sort();
protected:
	ElementType* data;
	size_t SIZE;
	inline int ParentOf(int Node);
	inline int LeftChild(int Node);
	inline int RightChild(int Node);
	//inline int HeapSize(void);
	void Heapify(int Node);
	void BuildHeap(void);
};

template<class ElementType>
BinaryHeap<ElementType>::BinaryHeap(ElementType* array, size_t sizeOfArray)
{
	SIZE = sizeOfArray;
	data = array;
	BuildHeap();

}

template<class ElementType>
void BinaryHeap<ElementType>::Sort(void) {
	BuildHeap();
	for (int i = SIZE / 2 - 1; i > 0; i--) {
		std::swap(data[0], data[i]);
		SIZE--;
		Heapify(0);
	}
}

template<class ElementType>
inline int BinaryHeap<ElementType>::ParentOf(int Node) {
	return (Node - 1) / 2;
}

template<class ElementType>
inline int BinaryHeap<ElementType>::LeftChild(int Node) {
	return 2 * Node + 1;
}

template<class ElementType>
inline int BinaryHeap<ElementType>::RightChild(int Node) {
	return 2 * Node + 2;
}

template<class ElementType>
void BinaryHeap<ElementType>::Heapify(int Node) {
	int largest = Node;
	int left = LeftChild(Node);
	int right = RightChild(Node);

	if (left < SIZE && data[left] > data[largest]) largest = left;
	if (right < SIZE && data[right] > data[largest]) largest = right;

	if (largest != Node) {
		std::swap(data[Node], data[largest]);
		Heapify(largest);
	}
}

template<class ElementType>
inline void BinaryHeap<ElementType>::BuildHeap(void) {
	for (int i = SIZE / 2 - 1; i >= 0; i--) {
		Heapify(i);
	}
}
