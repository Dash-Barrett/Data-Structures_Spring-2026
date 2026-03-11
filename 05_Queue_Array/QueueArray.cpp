#include "QueueArray.hpp"
#include <iostream>
#include <stdexcept>
using namespace std;

template <typename T, int size>
QueueDLL<T, size>::QueueDLL() {
    queue_size = 0;
    front_idx = back_idx = 0;
}
template <typename T, int size>
bool QueueDLL<T, size>::full() const {
    return (queue_size == size); 
}

template <typename T, int size>
bool QueueDLL<T, size>::empty() const {
    return (queue_size == 0); 
}

template <typename T, int size>
void QueueDLL<T, size>::enqueue(const T& val) {
    if (!full()) {
        data[back_idx] = val; // Set the last element with the value
        back_idx = (back_idx + 1) % size;
        queue_size++;
    }
}

template <typename T, int size>
const T& QueueDLL<T, size>::dequeue(){
    if(empty()){
        throw out_of_range("Empty Queue!");
    }
    int old_front = front_idx;
    front_idx = (front_idx + 1) % size;
    queue_size--;
    return data[old_front];
}


template <typename T, int size>
void QueueDLL<T, size>::print() const {
     cout << "{ ";
     if(!empty()){
        int i = front_idx;
        while(i != back_idx){
            cout << data[i];
            i = (i + 1) % size;
            if (i != back_idx){
                cout << ", ";
            }
        }
     }
     cout << " }\n";
}
