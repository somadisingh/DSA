#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Node
{
public:
    int val;
    vector<Node *> children;

    Node() {}

    Node(int _val)
    {
        val = _val;
    }

    Node(int _val, vector<Node *> _children)
    {
        val = _val;
        children = _children;
    }
};

class Solution
{
public:
    int maxDepth(Node *root)
    {

        if (root == NULL)
            return 0;
        queue<Node *> q;
        q.push(root);
        int depth = 0;

        while (!q.empty())
        {
            int size = q.size();

            for (int i = 0; i < size; i++)
            {

                Node *front = q.front();
                q.pop();
                for (int j = 0; j < front->children.size(); j++)
                {
                    q.push(front->children[j]);
                }
            }
            depth++;
        }
        return depth;
    }
};