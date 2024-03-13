#ifndef BINARYHEAP_H
#define BINARYHEAP_H
/*
* Include Header File from template
* to-do definition
* sort
*/
#include <iostream>

template <class ElementType>
class BinaryHeap {
public:
	BinaryHeap(int maxSize = 10 ^ 6);
	BinaryHeap(ElementType* array, size_t sizeOfArray, int maxSize = 10 ^ 6);
	//ElementType* Sort(void);
	~BinaryHeap(void);
	void Add(ElementType &Item);
	void Remove();
protected:
	ElementType* data;
	size_t currentSizeOfHeap;
	const int MAXSIZE;
	inline int ParentOf(int Node);
	inline int LeftChild(int Node);
	inline int RightChild(int Node);
	inline void Insert(ElementType &newElement);
	inline void Remove(void);
	inline size_t HeapSize(void);
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
inline BinaryHeap<ElementType>::BinaryHeap(ElementType* array, size_t sizeOfArray, int maxSize)
	: MAXSIZE(maxSize) {
	data = new ElementType[sizeOfArray];
	currentSizeOfHeap = sizeOfArray;
	for (int i = 0; i < currentSizeOfHeap; i++) {
		data[i] = array[i];
	}
	BuildHeap();
}

//template<class ElementType>
//ElementType* BinaryHeap<ElementType>::Sort(void) {
//	size_t SIZE = currentSizeOfHeap;
//	BuildHeap();
//	for (int i = SIZE / 2 - 1; i > 0; i--) {
//		std::swap(data[0], data[i]);
//		SIZE--;
//		Heapify(0);
//	}
//	return data;
//}

template<class ElementType>
inline BinaryHeap<ElementType>::~BinaryHeap(void) {
	if (data) delete[] data;
}

template<class ElementType>
inline void BinaryHeap<ElementType>::Add(ElementType& Item) {
	if (currentSizeOfHeap >= MAXSIZE) {
		std::cerr << "Heap overflow. Increase the size of heap" << std::endl;
		std::exit(EXIT_FAILURE);
	}
	Data[currentSizeOfHeap] = Item;
	Heapify(currentSizeOfHeap++);
;}

template<class ElementType>
inline void BinaryHeap<ElementType>::Remove() {
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
inline void BinaryHeap<ElementType>::Insert(ElementType& newElement) {
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
	currentSizeOfHeap = currentSizeOfHeap;
	for (int i = currentSizeOfHeap / 2 - 1; i >= 0; i--) {
		Heapify(i);
	}
}
#endif // BINARYHEAP_H