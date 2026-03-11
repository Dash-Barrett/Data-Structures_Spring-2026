#include "SLList.hpp"
#include <iostream>
using namespace std;

template<typename T>
SLList<T>::SLList() {
    head = nullptr;
    tail = nullptr;
    list_size = 0;
    
}

template<typename T>
SLList<T>::~SLList(){
    clear();
}

template<typename T>
SLList<T>::SLList(const SLList<T>& other){
    head = nullptr;
    tail = nullptr;
    list_size = 0;
    
    SLLNode<T>* cur = other.head;
    while (cur){
        this->push_back(cur->data);
        cur = cur->next;
    }
}

template<typename T>
SLList<T>& SLList<T>::operator=(const SLList<T>& other){
    if(!(this->empty())){
        this->clear();
    }
    SLLNode<T>* cur = other.head;
    while(cur){
        this->push_back(cur->data);
        cur = cur->next;
    }
    return *this;
}

template<typename T>
unsigned SLList<T>::size() const {
    return list_size;
}

template<typename T>
bool SLList<T>::empty() const{
    return (size() == 0);
}

template<typename T>
void SLList<T>::push_front(const T& val){
    // Add new node at beginning of list
    // SLLNode* new_node = new SLLNode(val);
    // new_node->next = head;
    // head = new_node;

    // Alternative Method
    head = new SLLNode<T>(val, head);

    // Increase list size
    list_size++;
    if(size() == 1){
        tail = head;
    }

}

template<typename T>
void SLList<T>::push_back(const T& val){
    // SLLNode* temp = head;
    if(empty()){
        push_front(val);
        return;
    }
    else{
        tail->next = new SLLNode<T>(val);
        tail = tail->next;

        list_size++;
    }
    // if(size() == 0){
    //     push_front(val);
    // }
    // else{
    //     for(int i = 0; i < size(); i++){
    //         if (temp->next != nullptr){
    //             temp = temp->next;
    //         }
    //         else{
    //             temp->next = new SLLNode(val);
    //         }
    //     }
    //     list_size++;
    // }
    
}

template<typename T>
void SLList<T>::pop_front(){
    if(!empty()){
        SLLNode<T>* old_head = head;
        head = head->next;
        delete old_head;

        list_size--;
        if(empty()){
            tail=head;
        }
    }

}

template<typename T>
void SLList<T>::pop_back() {
    if(!empty()){
        SLLNode<T>* cur = head;
        while(cur){
            if(cur->next == tail){
                tail = cur;
                SLLNode<T>* old_tail = tail->next;
                tail->next = nullptr;
                delete old_tail;
                list_size--;
                if(empty()){
                    head = tail;
                }
                return;
            }
            else if(size() == 1){
                SLLNode<T>* old_tail = cur;
                tail = nullptr;
                delete old_tail;
                head = tail;
                list_size--;
                return;
            }
                cur=cur->next;
        }
    }
    
}

template<typename T>
void SLList<T>::clear(){
    while(!empty()){
        pop_front();
    }
}

template<typename T>
void SLList<T>::print(void) const{
    SLLNode<T>* cur = head;
    cout << "{";
    while(cur){
        cout << cur->data;
        if (cur->next){
            cout << ", ";
        }
        cur = cur->next;
    }
    cout << "}\n";

}