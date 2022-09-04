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

// Breath First Search
class Solution
{
public:
    int maxDepth(TreeNode *root)
    {

        if (root == NULL)
            return 0;
        queue<TreeNode *> q;
        q.push(root);
        int depth = 0;

        while (!q.empty())
        {
            int size = q.size();

            for (int i = 0; i < size; i++)
            {

                TreeNode *front = q.front();
                q.pop();
                if (front->left)
                    q.push(front->left);
                if (front->right)
                    q.push(front->right);
            }
            depth++;
        }
        return depth;
    }
};

// Depth First Search

class Solution
{
public:
    int dfs(TreeNode *root)
    {
        if (root == NULL)
            return 0;

        int left = 1 + dfs(root->left);
        int right = 1 + dfs(root->right);

        return max(left, right);
    }

public:
    int maxDepth(TreeNode *root)
    {

        return dfs(root);
    }
};