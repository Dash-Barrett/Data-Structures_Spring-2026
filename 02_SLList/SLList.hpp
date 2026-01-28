#ifndef SLList_H
#define SLList_H

#include "SLLNode.hpp"

class SLList{
private:
    SLLNode* head; // pointer to first node
    SLLNode* tail; // pointer to last node
    unsigned list_size;
    

public:
    //No-arg Constructor
    SLList();

    //Copy Constructor TODO
    SLList(const SLList& other);

    //Destructor
    ~SLList();

    //Assignment operator TODO]
    SLList& operator=(const SLList& other);


    unsigned size() const;

    bool empty() const;
    void push_front(int val);
    void print() const;
    
    //TODO
    void push_back(int val);
    void pop_front(); // Remove the first element

    // TODO
    void pop_back();
    void clear(); // Clear the list
};


#endif