#include <iostream>
#include <queue>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// breath first search
class Solution
{
public:
    int minDepth(TreeNode *root)
    {
        if (root == NULL)
            return 0;
        queue<TreeNode *> q;
        q.push(root);
        int depth = 0;
        bool trigger = 0;

        while (!q.empty())
        {
            int size = q.size();

            for (int i = 0; i < size; i++)
            {
                TreeNode *front = q.front();
                q.pop();
                if (front->left == NULL && front->right == NULL) // as soon as node with no children is found, return depth
                {
                    trigger = 1;
                    break;
                }
                {
                    trigger = 1;
                    break;
                }
                if (front->left)
                    q.push(front->left);
                if (front->right)
                    q.push(front->right);
            }
            depth++;
            if (trigger == 1)
                return depth;
        }
        return depth;
    }
};

// depth first search
class Solution
{
public:
    int minDepth(TreeNode *root)
    {

        if (!root)
            return 0;
        if (!root->left)
            return 1 + minDepth(root->right);
        if (!root->right)
            return 1 + minDepth(root->left);

        return 1 + min(minDepth(root->left), minDepth(root->right));
    }
};