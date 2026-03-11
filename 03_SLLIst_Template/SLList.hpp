#ifndef SLList_H
#define SLList_H


#include "SLLNode.hpp"

template <typename T>
class SLList{
private:
    SLLNode<T>* head; // pointer to first node
    SLLNode<T>* tail; // pointer to last node
    unsigned list_size;
    

public:
    //No-arg Constructor
    SLList();

    //Copy Constructor TODO
    SLList(const SLList& other);

    //Destructor
    ~SLList();

    //Assignment operator TODO]
    SLList<T>& operator=(const SLList<T>& other);


    unsigned size() const;

    bool empty() const;
    void push_front(const T& val);
    void print() const;
    
    //TODO
    void push_back(const T& val);
    void pop_front(); // Remove the first element

    // TODO
    void pop_back();
    void clear(); // Clear the list
};


#endif