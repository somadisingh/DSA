#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    Node *links[26];
    bool containsKey(char ch)
    {
        return links[ch - 'a'];
    }
    void put(char ch, Node *node)
    {
        links[ch - 'a'] = node;
    }
    Node *get(char ch)
    {
        return links[ch - 'a'];
    }
};

int distinctSubstring(string &word)
{
    int count = 0;
    Node *root = new Node();
    for (int i = 0; i < word.size(); i++)
    {
        Node *node = root;
        for (int j = i; j < word.size(); j++)
        {
            if (!node->containsKey(word[j]))
            {
                count++;
                node->put(word[j], new Node());
            }
            node = node->get(word[j]);
        }
    }
    return count;
}
