#ifndef BINARYHEAP_H
#define BINARYHEAP_H

/*
* Include Header File from template
* to-do comments
* sort
*/

#include <iostream>

template <class ElementType>
class BinaryHeap {
public:
	BinaryHeap(int maxSize = pow(10, 6));
	BinaryHeap(const BinaryHeap<ElementType>& otherTree);
	BinaryHeap(ElementType* array, size_t sizeOfArray, int maxSize = pow(10, 6));
	//ElementType* Sort(void);
	~BinaryHeap(void);
	inline void Insert(ElementType& newElement);
	inline ElementType Remove(void);
	inline size_t HeapSize(void);
protected:
	ElementType* data;
	size_t currentSizeOfHeap;
	const int MAXSIZE;
	inline int ParentOf(int Node);
	inline int LeftChild(int Node);
	inline int RightChild(int Node);
	void Heapify(int Node);
	void BuildHeap(void);
};

template<class ElementType>
inline BinaryHeap<ElementType>::BinaryHeap(int maxSize)
	: MAXSIZE(maxSize) {
	data = new ElementType[MAXSIZE];
	currentSizeOfHeap = 0;
}

template<class ElementType>
inline BinaryHeap<ElementType>::BinaryHeap(const BinaryHeap<ElementType>& otherTree) 
	:MAXSIZE(otherTree.MAXSIZE) {
	data = new ElementType[MAXSIZE];
	currentSizeOfHeap = otherTree.currentSizeOfHeap;

	for (int i = 0; i < otherTree.currentSizeOfHeap; i++) {
		data[i] = otherTree.data[i];
	}
}

template<class ElementType>
inline BinaryHeap<ElementType>::BinaryHeap(ElementType* array, size_t sizeOfArray, int maxSize)
	: MAXSIZE(maxSize) {
	data = new ElementType[sizeOfArray];
	currentSizeOfHeap = sizeOfArray;
	for (int i = 0; i < currentSizeOfHeap; i++) {
		data[i] = array[i];
	}
	BuildHeap();
}

template<class ElementType>
inline BinaryHeap<ElementType>::~BinaryHeap(void) {
	if (data) delete[] data;
}

template<class ElementType>
inline void BinaryHeap<ElementType>::Insert(ElementType& Item) {
	if (currentSizeOfHeap >= MAXSIZE) {
		std::cerr << "Heap overflow. Increase the size of heap" << std::endl;
		std::exit(EXIT_FAILURE);
	}
	data[currentSizeOfHeap] = Item;
	Heapify(currentSizeOfHeap++);
;}

template<class ElementType>
inline ElementType BinaryHeap<ElementType>::Remove() {
	if (currentSizeOfHeap <= 0) {
		std::cerr << "Heap underflow!" << std::endl;
		std::exit(EXIT_FAILURE);
	}
	ElementType top = data[0];
	data[0] = data[--currentSizeOfHeap];
	Heapify(0);
	return top;
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
inline size_t BinaryHeap<ElementType>::HeapSize(void)
{
	return currentSizeOfHeap;
}

template<class ElementType>
void BinaryHeap<ElementType>::Heapify(int Node) {
	int largest = Node;
	int left = LeftChild(Node);
	int right = RightChild(Node);

	if (left < currentSizeOfHeap && data[left] > data[largest]) largest = left;
	if (right < currentSizeOfHeap && data[right] > data[largest]) largest = right;

	if (largest != Node) {
		std::swap(data[Node], data[largest]);
		Heapify(largest);
	}
}

template<class ElementType>
inline void BinaryHeap<ElementType>::BuildHeap(void) {
	for (int i = currentSizeOfHeap / 2 - 1; i >= 0; i--) {
		Heapify(i);
	}
}
#endif // BINARYHEAP_H