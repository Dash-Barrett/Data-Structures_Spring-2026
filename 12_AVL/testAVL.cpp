#include "AVLTree.hpp"
#include "AVLTree.cpp"

#include <iostream>
#include <string>

int main(void) {
    AVLTree<int> tree;
    for (int i = 1; i < 25; i++){
        tree.insert(i);
        tree.print();
    }
    std::cout << "DELETION\n";
    for(int i = 24; i <= 1; i--){
        tree.remove(i);
        tree.print();
    }
    
    return 0;
}


