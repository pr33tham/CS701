#pragma once
#pragma once
#include "BinaryHeap.h"

/*
* Include Header file from template
* to-do definition
* figure out how to pass <value, priority> as a single class into priority queue
*/
template <class ElementType>
class BinaryHeapPriorityQueue : public BinaryHeap<ElementType> {
public:
	BinaryHeapPriorityQueue(void);
	BinaryHeapPriorityQueue(ElementType* array, size_t sizeOfArray, int maxSize = 10 ^ 6);
	~BinaryHeapPriorityQueue();

	ElementType ExtractMax();
	void Insert(ElementType value, int priority);
	void IncreaseKey(ElementType value, int newPriority);
protected:

};

template<class ElementType>
inline BinaryHeapPriorityQueue<ElementType>::BinaryHeapPriorityQueue() : BinaryHeap() {

}
