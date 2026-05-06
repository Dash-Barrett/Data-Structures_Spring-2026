#include "MinHeap.hpp"
#include "MinHeap.cpp"
#include <cstdlib>
#include <vector>

template<typename T>
void heapSort(std::vector<T>& v){
    MinHeap<T> heap(v);
    for (int i = 0; i < v.size(); i++){
        v[i] = heap.deleteMin();
    }
}

int main(void) {
    MinHeap<int> heap;
    heap.insert(15);

    std::cout << "\n-----------------\n";
    heap.print();
    std::cout << "\n-----------------\n";

    heap.insert(11);

    std::cout << "\n-----------------\n";
    heap.print();
    std::cout << "\n-----------------\n";
    
    heap.insert(18);

    std::cout << "\n-----------------\n";
    heap.print();
    std::cout << "\n-----------------\n";
    
    heap.insert(9);

    std::cout << "\n-----------------\n";
    heap.print();
    std::cout << "\n-----------------\n";
    
    heap.insert(1);
    
    std::cout << "\n-----------------\n";
    heap.print();
    std::cout << "\n-----------------\n";
    
    // std::vector<int> v;

    // for (int i = 0; i < 10; i++) {
    //     int num = rand() % 1000;
    //     heap.insert(num);
    //     v.push_back(num);
    // }
    // MinHeap<int> heap2(v);

    // heap.print();
    // std::cout << "\n-----------------\n";
    // heap2.print();

    // std::cout << "\n-----------------\n";

    // for(int i = 0; i < 10; i++){
    //     heap.deleteMin();
    //     heap.print();
    //     std::cout << "\n-----------------\n";
    // }
    
    return 0;
}