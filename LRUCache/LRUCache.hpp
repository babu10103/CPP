#ifndef LRUCACHE_HPP
#define LRUCACHE_HPP

#include <iostream>
#include <unordered_map>
using namespace std;


class Node {
public:
    int key;
    int val;
    Node *left;
    Node *right;

    Node(int k, int v) : key(k), val(v), left(nullptr), right(nullptr){}
};

class LRUCache
{
private:
    int capacity;
    unordered_map<int, Node*> cache;
    Node *left;
    Node *right;
    
    void remove(Node *node);
    void insert(Node *node);

public:
    LRUCache(int cap);
    int get(int key);
    void put(int key, int value);
};

#endif