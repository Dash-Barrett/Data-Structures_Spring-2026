#include "SLList.hpp"
#include <iostream>
using namespace std;

SLList::SLList() {
    head = nullptr;
    tail = nullptr;
    list_size = 0;
    

}
SLList::~SLList(){
    clear();
}

SLList::SLList(const SLList& other){
    head = nullptr;
    tail = nullptr;
    list_size = 0;
    
    SLLNode* cur = other.head;
    while (cur){
        this->push_back(cur->data);
        cur = cur->next;
    }
}

SLList& SLList::operator=(const SLList& other){
    if(!(this->empty())){
        this->clear();
    }
    SLLNode* cur = other.head;
    while(cur){
        this->push_back(cur->data);
        cur = cur->next;
    }
    return *this;
}

unsigned SLList::size() const {
    return list_size;
}

bool SLList::empty() const{
    return (size() == 0);
}

void SLList::push_front(int val){
    // Add new node at beginning of list
    // SLLNode* new_node = new SLLNode(val);
    // new_node->next = head;
    // head = new_node;

    // Alternative Method
    head = new SLLNode(val, head);

    // Increase list size
    list_size++;
    if(size() == 1){
        tail = head;
    }

}

void SLList::push_back(int val){
    // SLLNode* temp = head;
    if(empty()){
        push_front(val);
        return;
    }
    else{
        tail->next = new SLLNode(val);
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

void SLList::pop_front(){
    if(!empty()){
        SLLNode* old_head = head;
        head = head->next;
        delete old_head;

        list_size--;
        if(empty()){
            tail=head;
        }
    }

}

void SLList::pop_back() {
    if(!empty()){
        SLLNode* cur = head;
        while(cur){
            if(cur->next == tail){
                tail = cur;
                SLLNode* old_tail = tail->next;
                tail->next = nullptr;
                delete old_tail;
                list_size--;
                if(empty()){
                    head = tail;
                }
                return;
            }
            else if(size() == 1){
                SLLNode* old_tail = cur;
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

void SLList::clear(){
    while(!empty()){
        pop_front();
    }
}

void SLList::print(void) const{
    SLLNode* cur = head;
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