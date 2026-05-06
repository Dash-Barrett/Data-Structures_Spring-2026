#ifndef HASHMAP_HPP
#define HASHMAP_HPP
#include "HashNode.hpp"
#include <vector>
using namespace std;

template <typename K, typename V>
class HashMap{
private:
    vector<HashNode<K,V>*> data;
    int n; // size of the table

    HashNode<K, V>* deleted; 

    int hash(const K& key) const;
    int searchIndex(const K& key) const;
public:
    HashMap(int size = 31);

    bool empty() const;
    bool full() const;

    void insert(const K& key, const V& value);
    void print() const;
    const V& search(const K& key) const;
    void remove(const K& key);

};

#include "HashMap.tpp"
#endif