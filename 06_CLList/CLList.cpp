#include "CLList.hpp"
#include <iostream>
using namespace std;

template <typename T>
CLList<T>::CLList() {
    tail = nullptr;
    list_size = 0;
}
// Check Methods
template <typename T>
bool CLList<T>::empty() const {
    return (list_size == 0);
}

// Insertion Methods
template <typename T>
void CLList<T>::push_front(const T& val) {
    if (empty()) {
        tail = new DLLNode<T>(val);
        tail->prev = tail;
        tail->next = tail;
        
    }
    else {
        tail->next = new DLLNode<T>(val, tail, tail->next);
        tail->next->next->prev = tail->next;
    }
    
    list_size++;
}

template <typename T>
void CLList<T>::push_back(const T& val){
    if (empty()) {
        tail = new DLLNode<T>(val);
        tail->prev = tail;
        tail->next = tail;

    }
    else{
        DLLNode<T>* to_move = tail;
        tail = new DLLNode<T>(val,to_move, to_move->next);
        to_move->next = tail;
        tail->next->prev = tail;

    }

    list_size++;
}

// Removal Methods
template <typename T>
void CLList<T>::pop_back(){
    if(!empty()){
        DLLNode<T>* to_del = tail;
        tail = tail->prev;
        tail->next = to_del->next;
        tail->next->prev = tail;
        
        delete to_del;
        list_size--;
    }
}

template <typename T>
void CLList<T>::pop_front(){
    DLLNode<T>* to_del = tail->next;
    tail->next = to_del->next;
    tail->next->prev = tail;
    
    delete to_del;
    list_size--;
}

// Print Methods
template <typename T>
void CLList<T>::print() const {
    if (empty()) {
        return;
    }
    DLLNode<T>* cur = tail->next;
    do {
        cout << cur->data;
        if (cur != tail) { // not the last node
            cout << " -> ";
        }
        cur = cur->next;
    } while (cur != tail->next);
    
    cout << endl;
}

template <typename T>
void CLList<T>::print_backwards() const {
    if (empty()) {
        return;
    }
    DLLNode<T>* cur = tail;

    do {
        cout << cur->data;
        if (cur != tail->next) { // not the last node
            cout << " <- ";
        }
        cur = cur->prev;
    } while (cur != tail);
    
    cout << endl;
}















