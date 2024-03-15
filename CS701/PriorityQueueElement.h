#ifndef PRIORITYQUEUEELEMENT_H
#define PRIORITYQUEUEELEMENT_H

/*************************************************************************
 *
 *  Pace University
 *  Spring 2024
 *  Advanced Algorithms
 *
 *  Course: CS 701-801
 *  Name: RUTHWIK PREETHAM, SURAPARAJU
 *  Collaborators: NONE
 *  References: INTRO TO ALGORITHMS, 3RD EDITION; CPROGRAMMING.COM;
 *
 *  Assignment: #1
 *  Problem: Write two generic classes: BinaryHeapPriorityQueue<T> and vEBtreePriorityQueue<T>, with methods ExtractMax(), Insert(value,priority),
 *	IncreaseKey(value,priority), and a constructor to create the data structure and populate it with a parametric collection of n items. (You may
 *	include other methods if you want, but these are the required.) Your methods must implement the pseudocode included in our textbook (3rd edition,
 *	Chapters 6 and 20). No points for code implementing other algorithms. Description: PUT A BRIEF DESCRIPTION HERE
 *  Input: 
 *  Output:
 *
 *  Visible data fields:
 *	size_t SIZE;										//Current number of elements
 *
 *  Visible methods:
 *  BinaryHeapPriorityQueue(int maxSize = pow(10, 6));
 *	ElementType ExtractMax();							//Returns and removes the max prioprity element
 *	void Insert(ElementType value, int priority);		//Inserts element to the heap
 *	void IncreaseKey(int index, int newPriority);		//Increases priority
 *	~BinaryHeapPriorityQueue();							//Deletes the heap array
 *
 *
 *   Remarks
 *   -------
 *
 *   PUT ALL NON-CODING ANSWERS HERE
 *
 *
 *
 *************************************************************************/

template<typename ValueType>
struct PriorityQueueElement {
    ValueType value;
    int priority;

    // Constructors
    PriorityQueueElement() : value(), priority(0) {}

    PriorityQueueElement(const ValueType& val, const int& prio) : value(val), priority(prio) {}
};

#endif // !PRIORITYQUEUEELEMENT_H