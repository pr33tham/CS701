#ifndef VEBTREEPRIORITYQUEUE_H
#define VEBTREEPRIORITYQUEUE_H

#include <unordered_map> 
#include "vEBTree.h"
#include "PriorityQueueElement.h"

template <class ElementType>
class vEBTreePriorityQueue {
public:
	vEBTreePriorityQueue(int universeSize);					//constructor initially for empty queue
	ElementType ExtractMax();								//Returns the max priority element
	void Insert(ElementType value, int priority);			//Inserts an element into the queue
	void IncreaseKey(ElementType value, int priority);		//Increase value to new priority
private:	
	vEBTree tree;											//vEBTree datastructure
	std::unordered_map<int, ElementType> priorityMap;		//hashmap to keep track of element and priority
};

template<class ElementType>
inline vEBTreePriorityQueue<ElementType>::vEBTreePriorityQueue(int universeSize)
	: tree(universeSize) {
}

template<class ElementType>
inline ElementType vEBTreePriorityQueue<ElementType>::ExtractMax(){
	if (tree.min == NIL) throw std::runtime_error("Queue is empty");
	int maxPriority = tree.Maximum(tree);
	return priorityMap[maxPriority];
}

template<class ElementType>
inline void vEBTreePriorityQueue<ElementType>::Insert(ElementType value, int priority) {
	priorityMap[priority] = value;
	tree.Insert(tree, priority);
}

template<class ElementType>
inline void vEBTreePriorityQueue<ElementType>::IncreaseKey(ElementType value, int priority) {
	if (tree.Member(tree, priority)) {
		int oldPriority = priorityMap[value];
		priorityMap[value] = priority;
		tree.Delete(tree, oldPriority);
		tree.Insert(tree, priority);
	}
	else {
		throw std::runtime_error("The current value is not found in the queue");
	}
}

#endif // !VEBTREEPRIORITYQUEUE_H

