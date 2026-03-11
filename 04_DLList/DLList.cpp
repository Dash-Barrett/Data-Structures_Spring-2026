#include "DLList.hpp"
#include <iostream>
using namespace std;

template <typename T>
DLList<T>::DLList() {
    head = new DLLNode<T>; // Sentinal head node
    tail = new DLLNode<T>; // Sentinal tial node
    
    head->next = tail;
    tail->previous = head;
    list_size = 0;
}

template<typename T>
void DLList<T>::push_front(const T& val){
    head->next = new DLLNode<T>(val, head, head->next);
    head->next->next->prev = head->next;
    list_size++;

}

template<typename T>
void DLList<T>::print() const{
    DLLNode<T>* cur = head->next;

    while (cur != tail){
        cout << cur->data;
        if(cur->next != tail){
            cout << " -> ";
        }
        cur = cur->next;
    }
}

template <typename T>
void DLList<T>::pop_back() {
    if (!empty()){
        DLLNode<T>* to_del = tail->prev;
        tail->prev = to_del->prev;
        tail->prev->next = tail;

        delete to_del;
        list_size--;
    }
}