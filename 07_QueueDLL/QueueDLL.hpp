#ifndef QUEUEARRAY_H
#define QUEUEARRAY_H
#include "DLList.hpp"

template <typename T>
class QueueDLL {
public:

    int         size() const; 
    int         length() const; // TODO
    bool        empty() const;
    void        clear(); // TODO
    
    void        enqueue(const T& val);
    T           dequeue(); // Throws std::out of range exception if nothing in queue.
    const T&    front() const; // Return the first element in the queue TODO
    void        print() const; 
    
private:
    DLList<T> data;
};

#endif