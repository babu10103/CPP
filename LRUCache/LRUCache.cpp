#include "LRUCache.hpp"

LRUCache::LRUCache(int cap)
{
    capacity = cap;
    cache.clear();
    left = new Node(0, 0);
    right = new Node(0, 0);
    left->right = right;
    right->left = left;
}

void LRUCache::remove(Node *node)
{
    Node *l = node->left;
    Node *r = node->right;
    l->right = r;
    r->left = l;
}

void LRUCache::insert(Node *node)
{
    Node *l = right->left;
    l->right = node;
    node->left = l;
    node->right = right;
    right->left = node;
}

int LRUCache::get(int key)
{
    if (cache.find(key) != cache.end())
    {
        Node *node = cache[key];
        remove(node);
        insert(node);
        return node->val;
    }
    return -1;
}

void LRUCache::put(int key, int value)
{
    if (cache.find(key) != cache.end())
    {
        remove(cache[key]);
        delete cache[key];
    }

    Node *newNode = new Node(key, value);
    cache[key] = newNode;
    insert(newNode);

    if (cache.size() > capacity)
    {
        Node *l = left->right;
        remove(l);
        cache.erase(l->key);
        delete l;
    }
}
