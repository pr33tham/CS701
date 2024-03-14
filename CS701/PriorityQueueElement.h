#ifndef PRIORITYQUEUEELEMENT_H
#define PRIORITYQUEUEELEMENT_H

template<typename ValueType>
struct PriorityQueueElement {
    ValueType value;
    int priority;

    // Constructors
    PriorityQueueElement() : value(), priority(0) {}

    PriorityQueueElement(const ValueType& val, const int& prio) : value(val), priority(prio) {}
};

#endif // !PRIORITYQUEUEELEMENT_H