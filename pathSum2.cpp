#include <iostream>
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
    void traverse(TreeNode *root, int targetSum, vector<int> &temp, vector<vector<int>> &ans)
    {
        if (!root)
            return;
        if (!root->left && !root->right)
        {
            if (targetSum == root->val)
            {
                temp.push_back(root->val);
                ans.push_back(temp);
                temp.pop_back();
                targetSum -= root->val;
                return;
            }
            else
                return;
        }

        targetSum -= root->val;
        temp.push_back(root->val);

        traverse(root->left, targetSum, temp, ans);
        traverse(root->right, targetSum, temp, ans);

        targetSum += root->val;
        temp.pop_back();

        return;
    }

public:
    vector<vector<int>> pathSum(TreeNode *root, int targetSum)
    {
        vector<vector<int>> ans;
        if (!root)
            return ans;
        vector<int> temp;
        traverse(root, targetSum, temp, ans);
        return ans;
    }
};

int main()
{
    TreeNode *root = new TreeNode(5);
    root->left = new TreeNode(4);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(11);
    root->left->left->left = new TreeNode(7);
    root->left->left->right = new TreeNode(2);
    root->right->left = new TreeNode(13);
    root->right->right = new TreeNode(4);
    root->right->right->left = new TreeNode(5);
    root->right->right->right = new TreeNode(1);

    Solution s;
    vector<vector<int>> ans = s.pathSum(root, 22);
    for (auto i : ans)
    {
        for (auto j : i)
            cout << j << " ";
        cout << endl;
    }
    return 0;
}