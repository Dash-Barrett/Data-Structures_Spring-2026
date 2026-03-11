#include "BTNode.hpp"
#include "BST.hpp"
#include "BST.cpp"
#include <iostream>
using namespace std;

int main(void){
    BST<int> tree;
    tree.insert(2);
    tree.insert(1);
    tree.insert(3);
    tree.insert(4);

    tree.print();

    BTNode<int>* found = tree.search(2);

    tree.rotateRight(found);
    tree.print();

    tree.rotateLeft(found);
    tree.print();
    

    // tree.insert_recursive(4);

    // cout << "Is Full Tree? " << tree.isFullTree() << endl;
    // tree.inorder();
    // tree.preorder();
    // tree.postorder();


    
    // BTNode<int>* node = tree.search(2);
    // if(node) {
    //     cout << "Found" <<endl;
    // }
    // else{
    //     cout << "Not Found" << endl;
    // }

    // BST<int> parent_test;
    // parent_test.insert(1);
    // parent_test.insert(2);
    // parent_test.insert(3);
    // BTNode<int>* node2 = parent_test.search_parent(2);
    // cout << node2->data << endl;
    return 0;
}