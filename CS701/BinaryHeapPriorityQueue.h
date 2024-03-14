#ifndef  BINARYHEAPPRIORITYQUEUE_H
#define BINARYHEAPPRIORITYQUEUE_H

#include <iostream>
#include "PriorityQueueElement.h"

/*
* Include Header File from template
* to-do comments
* fix bugs
*/

template<class ElementType> 
class BinaryHeapPriorityQueue {
public:
	BinaryHeapPriorityQueue(int maxSize = pow(10, 6));	
	ElementType ExtractMax();						//Returns and removes the max prioprity element
	void Insert(ElementType value, int priority);	//Inserts element to the heap
	void IncreaseKey(int index, int newPriority);	//Increases priority 
	~BinaryHeapPriorityQueue();						//Deletes the heap array
	size_t SIZE;									//Current number of elements
	PriorityQueueElement<ElementType>* data;		//Data array
private:
	const int MAXSIZE;					//Maximum number of elements
	inline int ParentOf(int Node);		//Returns parents location
	inline int LeftChild(int Node);		//Returns left child location
	inline int RightChild(int Node);	//Returns right child location
	void Heapify(int Node);				//Checks and swaps if heap property is not followed
	void BuildHeap(void);				//Builds heap for all nodes with heap property
};

template<class ElementType>
inline BinaryHeapPriorityQueue<ElementType>::BinaryHeapPriorityQueue(int maxSize)
	: MAXSIZE(maxSize) {
	data = new PriorityQueueElement<ElementType>[MAXSIZE];
	SIZE = 0;
}

template<class ElementType>
inline ElementType BinaryHeapPriorityQueue<ElementType>::ExtractMax() {
	if (SIZE <= 0) {
		std::cerr << "Heap underlow!" << std::endl;
		std::exit(EXIT_FAILURE);
	}
	PriorityQueueElement<ElementType> max = data[0];
	data[0] = data[--SIZE];
	Heapify(0);
}

template<class ElementType>
inline void BinaryHeapPriorityQueue<ElementType>::Insert(ElementType value, int priority) {
	if (SIZE >= MAXSIZE) {
		std::cerr << "Heap overflow. Increase the size of heap" << std::endl;
		std::exit(EXIT_FAILURE);
	}
	SIZE++;
	PriorityQueueElement<ElementType> newElement = { value, -1 };
	data[SIZE - 1].value = value;
	IncreaseKey(SIZE, priority);	
}

template<class ElementType>
inline void BinaryHeapPriorityQueue<ElementType>::IncreaseKey(int index, int newPriority) {
	if (data[index].priority > newPriority) {
		std::cerr << "New Priority is smaller than current key!" << std::endl;
		std::exit(EXIT_FAILURE);
	}
	data[index].priority = newPriority;
	while (index > 0 and data[ParentOf(index)].priority < data[index].priority) {
		std::swap(data[index], data[ParentOf(index)]);
		index = ParentOf(index);
	}
}

template<class ElementType>
inline BinaryHeapPriorityQueue<ElementType>::~BinaryHeapPriorityQueue() {
	if (data) delete[] data;
}

template<class ElementType>
inline int BinaryHeapPriorityQueue<ElementType>::ParentOf(int Node) {
	return (Node - 1) / 2;
}

template<class ElementType>
inline int BinaryHeapPriorityQueue<ElementType>::LeftChild(int Node) {
	return 2 * Node + 1;
}

template<class ElementType>
inline int BinaryHeapPriorityQueue<ElementType>::RightChild(int Node) {
	return 2 * Node + 2;
}

template<class ElementType>
inline void BinaryHeapPriorityQueue<ElementType>::Heapify(int Node){
	int largest = Node;
	int left = LeftChild(Node);
	int right = RightChild(Node);

	std::cout << "Left for " << Node << " is " << left << std::endl;
	std::cout << "Right for " << Node << " is " << right << std::endl;

	if (left <= SIZE && data[left].priority > data[largest].priority) largest = left;
	if (right <= SIZE && data[right].priority > data[largest].priority) largest = right;

	std::cout << "Largest priority is " << largest << std::endl;

	if (largest != Node) {
		std::swap(data[Node], data[largest]);
		std::cout << "Data swapped " << data[Node].value << " " << data[largest].value << std::endl;
		Heapify(largest);
	}
}

template<class ElementType>
inline void BinaryHeapPriorityQueue<ElementType>::BuildHeap(void) {
	for (int i = SIZE / 2 - 1; i >= 0; i--) {
		Heapify(data[i].value);
	}
}

#endif // ! BINARYHEAPPRIORITYQUEUE_H