#pragma once

/*
//to-do definition
*/

#include <iostream>

template <class ElementType>
class BinaryHeap {
public:
	BinaryHeap(ElementType* array, size_t sizeOfArray);
	ElementType* Sort(void);
	~BinaryHeap(void);
protected:
	ElementType* data;
	size_t SIZE;
	inline int ParentOf(int Node);
	inline int LeftChild(int Node);
	inline int RightChild(int Node);
	inline int HeapSize(void);
	void Heapify(int Node);
};