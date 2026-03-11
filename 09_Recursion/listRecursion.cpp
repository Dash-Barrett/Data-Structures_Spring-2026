#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int d = 0, Node* n = nullptr) : data(d), next(n) {}

};

void print_list(Node* head);
void print_list_backwards(Node* head);

Node* reverse_list(Node* head);
Node* swap_pairs(Node* head); //TODO

int main(void){
    //Create a linked list
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);

    print_list(head);
    print_list_backwards(head);

    cout << "\n";

    head = reverse_list(head);
    print_list(head);
    
    
    return 0;
}

void print_list(Node* head){
    if(!head){
        cout << "\n";
        return;
    }
    else{
        cout << head->data << " ";
        print_list(head->next);
    }
}

void print_list_backwards(Node* head){
    if(!head){
        return;
    }
    else{
        print_list_backwards(head->next);
        cout << head->data << " ";
    }
}

Node* reverse_list(Node* head){
    if(!head || !head->next){
        return head;
    }
    else{
        Node* p = reverse_list(head->next);
        head->next->next = head;
        head->next = nullptr;

        return p;
    }
}

Node* swap_pairs(Node* head){
    if(!head || !head->next){
        return head;
    }
    Node* nextPair = head->next->next;
    head->next->next = head;
    head = head->next;
    head->next->next = swap_pairs(nextPair);
    return head;
}