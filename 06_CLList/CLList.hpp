#ifndef CLLIST_H
#define CLLIST_H
#include "DLLNode.hpp"

template <typename T>
class CLList {
public:

    CLList(); // No-Arg Constructor

    // Checking Methods
    bool empty() const; // Checks if list is empty

    // Insertion Methods
    void push_front(const T& val); // Insert at beginning
    void push_back(const T& val); // Insert at the end

    // Removal Methods
    void pop_back(); // Remove the last element (node)
    void pop_front(); // Remove the first element (node)

    // Printing Methods
    void print() const; // Prints everything in list
    void print_backwards() const; // Prints everything in list but back to front

private:
    DLLNode<T>* head; // The pointer to the first node
    DLLNode<T>* tail; // The pointer to the last node
    unsigned list_size;

};

#endif