#ifndef BST_H
#define BST_H
#include "BTNode.hpp"
#include <string>

template <typename T>
class BST{
private:
    BTNode<T>* root;
    BTNode<T>* insert_recursive(BTNode<T>* node, const T& val);
    void inorder(BTNode<T>* node) const;
    void preorder(BTNode<T>* node) const;
    void postorder(BTNode<T>* node) const;
    
    void deleteLeaf(BTNode<T>* child, BTNode<T>* parent);
    void deleteNodeWithOneChild(BTNode<T>* child, BTNode<T>*parent);
    void deleteNodeWithTwoChildren(BTNode<T>* node);

    bool isFullTree(BTNode<T>* node) const;
    void print(const std::string& prefix, BTNode<T>* node, bool isRight) const;
    BTNode<T>* getMinNode(BTNode<T>* node) const;
    int getHeight(BTNode<T>* node) const;
    int getBalance(BTNode<T>* node) const;

public:
    BST();
    void insert(const T& val);
    void insert_recursive(const T& val);
    
    BTNode<T>* getMinNode() const;
    void deleteNode(const T& val);
    BTNode<T>* search(const T& val) const;
    BTNode<T>* search_parent(const T& val) const;
    bool empty() const;
    void print() const;
    void rotateRight(BTNode<T>*& node);
    void rotateLeft(BTNode<T>*& node);

    // Traversial of the Tree
    void inorder() const;
    void preorder() const;
    void postorder() const;

    bool isFullTree() const;

    
};



#endif