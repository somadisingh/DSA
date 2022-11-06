#include "iostream"
#include "queue"
#include "map"
#include "vector"

using namespace std;
template <typename T>
class BinaryTreeNode
{
public:
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

vector<int> bottomView(BinaryTreeNode<int> *root)
{

    vector<int> v;
    if (!root)
        return v;
    map<int, int> m;
    queue<pair<BinaryTreeNode<int> *, int>> q;
    q.push({root, 0});
    while (!q.empty())
    {
        auto t = q.front();
        q.pop();
        BinaryTreeNode<int> *node = t.first;
        int y = t.second;
        m[y] = node->data;
        if (node->left)
            q.push({node->left, y - 1});
        if (node->right)
            q.push({node->right, y + 1});
    }

    for (auto a : m)
        v.push_back(a.second);
    return v;
}
