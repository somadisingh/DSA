#include <iostream>
#include <unordered_map>

using namespace std;

class LRUCache
{
public:
    class node // defining the doubly linked list (dll)
    {
    public:
        int key;
        int val;
        node *next;
        node *prev;
        node(int _key, int _val) // constructor for dll
        {
            key = _key;
            val = _val;
        }
    };

    node *head = new node(-1, -1); // dummy head
    node *tail = new node(-1, -1); // dummy tail

    int cap;
    unordered_map<int, node *> m; // hashmap to store the key and the address of the node

    LRUCache(int capacity) // initial config
    {
        cap = capacity;
        head->next = tail; // connecting the head and tail
        tail->prev = head; // connecting the head and tail
    }

    void insertNode(node *newnode)
    { // insert new node just after head
        node *temp = head->next;
        newnode->next = temp; // newnode's next will contain the earlier node
        newnode->prev = head; // newnode's prev will store head
        head->next = newnode; // head's next will store newnode
        temp->prev = newnode; // the prev of earlier node after head store newnode
    }

    void removeNode(node *delnode) // remove the node before tail
    {
        node *delprev = delnode->prev; // node before the node to be deleted: let x
        node *delnext = delnode->next; // node after the node to be deleted: let y
        delprev->next = delnext;       // x's next will point to y
        delnext->prev = delprev;       // y's prev will point to x
    }

    int get(int _key) // fetch the value of key
    {
        if (m.find(_key) != m.end())
        {                            // if the key is found
            node *ansnode = m[_key]; // fetch the address of key in dll
            int ans = ansnode->val;  // fetch value stored in that node
            m.erase(_key);           // remove the record of key with old address
            removeNode(ansnode);     // remove the old node with key in dll
            insertNode(ansnode);     // insert the node with new address
            m[_key] = head->next;    // map now stores the latest address after head
            return ans;
        }
        return -1;
    }

    void put(int _key, int value) // insert a new key
    {
        if (m.find(_key) != m.end())
        {                         // if the value to be inserted is present
            node *curr = m[_key]; // fetch its address in dll
            m.erase(_key);        // remove the record from map
            removeNode(curr);     // remove node from dll
        }
        if (m.size() == cap)
        {
            m.erase(tail->prev->key); // remove LRU record from map
            removeNode(tail->prev);   // remove the lru node
        }
        // insert the new record
        insertNode(new node(_key, value)); // insert the new node
        m[_key] = head->next;              // insert key with address of last used
    }
};
