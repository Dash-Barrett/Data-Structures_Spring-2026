#include "HashMap.hpp"
#include <vector>
#include <iostream>
#include <stdexcept>
using namespace std;

template <typename K, typename V>
HashMap<K, V>::HashMap(int size) : n(0){
    data.resize(size, nullptr);

    deleted = new HashNode<K, V>(K(), V());
}

template <typename K, typename V>
bool HashMap<K, V>::empty() const{
    return n == 0;
}

template <typename K, typename V>
bool HashMap<K, V>::full() const{
    return n == data.size();
}

template <typename K, typename V>
int HashMap<K, V>::hash(const K& key) const{
    return key % data.size();
}

template <typename K, typename V>
void HashMap<K, V>::insert(const K& key, const V& value){
    if (full()) {
        return;
    }

    // Find the hash
    int index = hash(key);

    while (data[index] && data[index] != deleted) {
        index = (index + 1) % data.size();  // Go to the next position
    }

    // Insert the node
    data[index] = new HashNode<K,V>(key, value);
    n++;
}

template <typename K, typename V>
void HashMap<K, V>::print() const{
    for (int i = 0; i < data.size(); i++) {
        cout << i << " ";
        if (data[i] == nullptr) {
            cout << "nullptr\n";
        }
        else if (data[i] == deleted) {
            cout << "deleted\n";
        }
        else {
            cout << "{ " << data[i]->key << "; " << data[i]->value << " }\n";
        }
    }
}

template <typename K, typename V>
const V& HashMap<K, V>::search(const K& key) const{
    if(!empty()){
        int idx = hash(key);
        if(data[idx]->key == key){
            return data[idx]->value;
        }
    }
    throw logic_error("can't find");
}

template <typename K, typename V>
void HashMap<K, V>::remove(const K& key){
    if (empty()){
        return;
    }
    int index = hash(key);
    data[index] = deleted;
    return;
}
