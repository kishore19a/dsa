#include <iostream>
#include <unordered_map>

struct Node
{
    int key, val;
    Node *next;
    Node *prev;

    Node() : next(nullptr), prev(nullptr) {}
    Node(int k, int v) : key(k), val(v), next(nullptr), prev(nullptr) {}
};

class LRU
{
public:
    LRU(int cap);
    ~LRU() {}

    int get(int key);
    void put(int key, int val);
    void print();

private:
    Node *head, *tail;
    int _cap;
    std::unordered_map<int, Node*> lruCache;

    void deleteNode(Node* node);
    void addNode(Node* node);
};

LRU::LRU(int cap)
  : _cap(cap)
{
    head = new Node(-1, -1);
    tail = new Node(-1, -1);

    head->next = tail;
    tail->prev = head;
}

void LRU::deleteNode(Node* node)
{
    Node* delPrev = node->prev;
    Node* delNext = node->next;

    delPrev->next = delNext;
    delNext->prev = delPrev;

    delete(node);
    node = nullptr;
}

void LRU::addNode(Node* node)
{
    Node* headNext = head->next;
    node->next = headNext;
    headNext->prev = node;

    head->next = node;
    node->prev = head;
}

void LRU::put(int key, int val)
{
    if(lruCache.find(key) != lruCache.end())
    {
        Node* found = lruCache[key];
        lruCache.erase(key);
        deleteNode(found);
    }
    else if(lruCache.size() == _cap)
    {
        lruCache.erase(tail->prev->key);
        deleteNode(tail->prev);
    }

    Node* newNode = new Node(key, val);
    addNode(newNode);
    lruCache[key] = newNode;
}

int LRU::get(int key)
{
    if(lruCache.find(key) != lruCache.end())
    {
        Node* found = lruCache[key];
        Node* res = new Node(key, found->val);
        lruCache.erase(key);
        deleteNode(found);
        addNode(res);
        lruCache[key] = head->next;

        return res->val;
    }

    return -1;
}

void LRU::print()
{
    Node* temp{head->next};
    while(temp != tail)
    {
        std::cout << "{" << temp->key << "," << temp->val << "}" << " ";
        temp = temp->next;
    }
    std::cout << std::endl;
}

int main(int argc, char const *argv[])
{
    LRU lru(2);

    lru.put(1, 1);
    lru.print();

    lru.put(2, 2);
    lru.print();

    int val = lru.get(1);
    std::cout << "lruCache[" << 1 << "] = " << val << std::endl;
    lru.print();

    lru.put(3, 3);
    lru.print();

    val = lru.get(2);
    std::cout << "lruCache[" << 2 << "] = " << val << std::endl;
    lru.print();

    return 0;
}
