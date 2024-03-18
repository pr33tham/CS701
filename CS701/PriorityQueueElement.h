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
 *  Problem: Not in context with any problem
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