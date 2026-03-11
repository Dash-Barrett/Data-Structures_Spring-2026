#include "QueueDLL.hpp"

//template<typename T>

template<typename T>
void QueueDLL<T>::enqueue(const T& val){
    data.push_back(val);
}

template<typename T>
void QueueDLL<T>::print() const{
    data.print();
}

template<typename T>
int QueueDLL<T>::size() const{
    return data.size();
}

template<typename T>
bool QueueDLL<T>::empty() const{
    return data.empty();
}

template<typename T>
void QueueDLL<T>::clear() {
    data.clear();
}

template<typename T>
T QueueDLL<T>::dequeue() {
    if (!empty()){
        T temp = data.front();
        data.pop_front();
        return temp;
    }
    else{

    }
}

template <typename T>
const T& QueueDLL<T>::front() const{
    return data.front();
}
