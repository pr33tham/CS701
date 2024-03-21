#ifndef PRIORITYQUEUEELEMENT_H
#define PRIORITYQUEUEELEMENT_H

template<typename ValueType>
struct PriorityQueueElement {
    ValueType value;    //Actual value for queue
    int priority;       //Priotity of the value

    // Constructors
    PriorityQueueElement() : value(), priority(0) {}

    PriorityQueueElement(const ValueType& val, const int& prio) : value(val), priority(prio) {}
};

#endif // !PRIORITYQUEUEELEMENT_H