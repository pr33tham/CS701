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
 *  References: NONE
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
 *  ValueType value;    //Actual value for queue
 *  int priority;       //Priotity of the value
 *
 *  Visible methods:
 *  NONE
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
    ValueType value;    //Actual value for queue
    int priority;       //Priotity of the value

    // Constructors
    PriorityQueueElement() : value(), priority(0) {}

    PriorityQueueElement(const ValueType& val, const int& prio) : value(val), priority(prio) {}
};

#endif // !PRIORITYQUEUEELEMENT_H