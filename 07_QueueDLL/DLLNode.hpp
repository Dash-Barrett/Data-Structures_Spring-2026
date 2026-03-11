#ifndef DLLNODE_H
#define DLLNODE_H

template <typename T>
class DLLNode {
public:
    DLLNode(const T& d= T(), DLLNode<T> *n = nullptr, DLLNode<T> *p = nullptr) {
        data = d;
        next = n;
        previous = p;
    }

    T data;
    DLLNode<T> *next; // pointer to the next node
    DLLNode<T> * previous // pointer to the previous node

};



#endif