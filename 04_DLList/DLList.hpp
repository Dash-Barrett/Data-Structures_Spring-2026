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

    // //Copy Constructor TODO
    // DLList(const DLList<T>& other);

    // //Destructor
    // ~DLList();

    // //Assignment operator TODO]
    // DLList<T>& operator=(const DLList<T>& other);


    // unsigned size() const;

    // bool empty() const;
    void push_front(const T& val);
    void print() const;
    
    //TODO
    // void push_back<T>(const T& val);
//     void pop_front<T>(); // Remove the first element

//     // TODO
    void pop_back();
//     void clear<T>(); // Clear the list
};

#endif