#include "Stack.hpp"
#include <iostream>
#include <stdexcept>
using namespace std;

template<typename T, int size>
StackArray::Stack<T, size>::Stack() : top_idx(-1){ }

template<typename T, int size>
void StackArray::Stack<T, size>::push(const T& val){
    if(full()){
        throw out_of_range("Full stack");
    }
    else{
        data[++top_idx] = val;
    }
}

template<typename T, int size>
bool StackArray::Stack<T, size>::empty() const{
    return (top_idx == -1);
}

template<typename T, int size>
bool StackArray::Stack<T, size>::full() const{
    return (top_idx == size - 1);
}

template<typename T, int size>
void StackArray::Stack<T, size>::print() const{
    int i = top_idx;
    while (i >= 0){
        cout << data[i] << endl;
        i--;
    }
}

template<typename T, int size>
T StackArray::Stack<T, size>::pop(){
    if(empty()){
        throw out_of_range("Empty stack");
    }
    else{
        return data[top_idx--];
    }
}

template<typename T, int size>
const T& StackArray::Stack<T, size>::top() const{
    if(empty()){
        throw out_of_range("Empty stack");
    }
    else{
        return data[top_idx];
    }
}