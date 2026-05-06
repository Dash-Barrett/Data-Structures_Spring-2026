#ifndef TRIE_HPP
#define TRIE_HPP
#include <string>
#include <vector>
#include "TrieNode.hpp"

class Trie{
private:
    TrieNode* root;
    void print(TrieNode* node, std::string& word) const;
public:
    Trie();
    Trie(std::vector<std::string>& v);
    void insert(const std::string& s);
    bool search(const std::string& s) const;
    void print() const;

    bool empty() const;

};

#endif