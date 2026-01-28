#include "SLLNode.hpp"
#include <iostream>
using namespace std;

int main(void){
    // Create SLL Nodes
    SLLNode *n1 = new SLLNode(1);
    SLLNode *n2 = new SLLNode(2);
    SLLNode *n3 = new SLLNode(3);
    SLLNode *n4 = new SLLNode(4);

    // Alternative Creation
    SLLNode *b = new SLLNode(10);
    b->next = new SLLNode(10);
    b->next->next = new SLLNode(10);

    // Link the nodes!
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;

    // Iterating through the nodes!
    SLLNode *cur = n1;
    while (cur != nullptr){
        cout << cur->data;
        if(cur->next != nullptr){
            cout << " -> ";
        }
        cur = cur->next; // ALlows it to go the the next node.
    }

    // Free Memory
    delete n1->next->next->next;
    delete n1->next->next;
    delete n1->next;
    delete n1;

    return 0;

}