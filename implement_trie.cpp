#include <bits/stdc++.h>

using namespace std;

/*
    Your Trie object will be instantiated and called as such:
    Trie* obj = new Trie();
    obj->insert(word);
    bool check2 = obj->search(word);
    bool check3 = obj->startsWith(prefix);
 */

class TrieNode
{
public:
    char data;
    TrieNode *children[26];
    bool isTerminal;

    TrieNode(char data)
    {
        this->data = data;
        for (int i = 0; i < 26; i++)
            children[i] = NULL;
        isTerminal = false;
    }
};

class Trie
{
    TrieNode *root;

public:
    /** Initialize your data structure here. */
    Trie()
    {
        root = new TrieNode('\0');
    }

    /** Inserts a word into the trie. */
    void insertUtil(TrieNode *root, string word)
    {
        // base case
        if (word.length() == 0)
        {
            root->isTerminal = true;
            return;
        }
        // assuming all letter lcase:
        int index = word[0] - 'a'; // mapping alphabets
        TrieNode *child;

        // if children are present:
        if (root->children[index] != NULL)
        {
            child = root->children[index];
        }
        else
        {
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }
        // recursive call to the next letter
        insertUtil(child, word.substr(1));
    }
    void insert(string word)
    {
        insertUtil(root, word);
    }

    /** Returns if the word is in the trie. */
    bool searchTrie(TrieNode *root, string word)
    {
        // base: if you're on the last letter, return isTerminal status
        if (word.length() == 0)
            return root->isTerminal;

        int index = word[0] - 'a';
        TrieNode *child;

        // if character is present
        if (root->children[index] != NULL)
            child = root->children[index];
        // if absent
        else
            return false;

        // recursion call
        return searchTrie(child, word.substr(1));
    }
    bool search(string word)
    {
        return searchTrie(root, word);
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool seePrefix(TrieNode *root, string word)
    {
        // base: if you're on the last letter, return isTerminal status
        if (word.length() == 0)
            return true;

        int index = word[0] - 'a';
        TrieNode *child;

        // if character is present
        if (root->children[index] != NULL)
            child = root->children[index];
        // if absent
        else
            return false;

        // recursion call
        return seePrefix(child, word.substr(1));
    }
    bool startsWith(string prefix)
    {
        return seePrefix(root, prefix);
    }
};