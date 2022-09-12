#include <iostream>
#include <vector>

using namespace std;

template <typename T>
class TreeNode
{
public:
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }

    ~TreeNode()
    {
        if (left)
            delete left;
        if (right)
            delete right;
    }
};

void leftBound(TreeNode<int> *root, vector<int> &ans)
{
    TreeNode<int> *node = root->left;
    while (node)
    {
        if (node->left || node->right) // if node is not a leaf node
            ans.push_back(node->data);
        if (node->left)
            node = node->left;
        else
            node = node->right;
    }
}

void rightBound(TreeNode<int> *root, vector<int> &ans)
{
    TreeNode<int> *node = root->right;
    vector<int> temp;
    while (node)
    {
        if (node->left || node->right)
            temp.push_back(node->data);
        if (node->right)
            node = node->right;
        else
            node = node->left;
    }
    for (int i = temp.size() - 1; i >= 0; i--)
    {
        ans.push_back(temp[i]); // since the right bound is traversed in reverse order we need to push it in reverse order
    }
}

void leafBound(TreeNode<int> *root, vector<int> &ans)
{
    if (!root->left && !root->right)
    {
        ans.push_back(root->data);
        return;
    }
    if (root->left)
        leafBound(root->left, ans);
    if (root->right)
        leafBound(root->right, ans);
}

vector<int> traverseBoundary(TreeNode<int> *root)
{
    vector<int> ans;
    if (!root)
        return ans;
    if ((root->left) || (root->right)) // if the root is not leaf the insert into ans
        ans.push_back(root->data);
    leftBound(root, ans);  // traverse the left boundary
    leafBound(root, ans);  // traverse the leaf nodes
    rightBound(root, ans); // traverse the right boundary
    return ans;
}