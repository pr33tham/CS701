#pragma once
#include "BinaryHeap.h"

template <class ElementType>
class BinaryHeapPriorityQueue :public BinaryHeap {
public:
	BinaryHeapPriorityQueue(Element);
	ElementType ExtractMax();
	void Insert(ElementType value, int priotity);
	void IncreaseKey(ElementType value, int newPriority);

protected:

};

template<class ElementType>
inline BinaryHeapPriorityQueue<ElementType>::BinaryHeapPriorityQueue() {

}
