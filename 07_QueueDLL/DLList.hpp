#ifndef DLLNODE_H
#define DLLNODE_H
#include "DLLNode.hpp"

template<typename T>
class DLList{
    private:
    DLLNode<T>* head; // pointer to first node
    DLLNode<T>* tail; // pointer to last node
    unsigned list_size;
    

public:
    //No-arg Constructor
    DLList();

   bool        empty() const; // Returns true if list is empty
    void        push_front(const T& val); // Insert the new node at the beginning
    void        push_back(const T& val); // Insert the new node at the end
    void        print() const; // Print the list
    void        print_backwards() const; // Prints the list but backwards
    void        pop_back(); // Remove the last element (node)
    void        pop_front(); // Removes the first element (node)
    const T&    front() const;
};

#endif