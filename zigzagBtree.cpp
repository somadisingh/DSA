#include <iostream>
#include <queue>
#include <vector>

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

class Solution
{
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {

        bool toggle = 0;

        vector<vector<int>> ans;
        if (root == NULL)
            return ans;

        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty())
        {
            int size = q.size();
            vector<int> temp(size);
            if (toggle == 0)
            {
                for (int i = 0; i < size; i++)
                {
                    TreeNode *front = q.front();
                    temp[i] = front->val;
                    q.pop();

                    if (front->left)
                        q.push(front->left);
                    if (front->right)
                        q.push(front->right);
                }
            }
            else if (toggle == 1)
            {
                for (int i = 0; i < size; i++)
                {
                    TreeNode *front = q.front();
                    temp[size - i - 1] = front->val;
                    q.pop();

                    if (front->left)
                        q.push(front->left);
                    if (front->right)
                        q.push(front->right);
                }
            }
            toggle = !toggle;
            ans.push_back(temp);
        }
        return ans;
    }
};