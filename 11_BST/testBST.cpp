#include "BTNode.hpp"
#include "BST.hpp"
#include "BST.cpp"
#include <iostream>
using namespace std;

int main(void){
    BST<int> tree;
    tree.insert(20);
    tree.insert(10);
    tree.insert(5);
    tree.insert(15);
    tree.insert(4);
    tree.insert(40);
    tree.insert(30);
    tree.insert(50);
    tree.insert(35);

    tree.print();
    BTNode<int>* found = tree.search(20);
    cout << "Leaves:" << tree.count_leaves(found) << endl;

    

    // tree.rotateRight(found);
    // tree.print();

    // tree.rotateLeft(found);
    // tree.print();
    

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