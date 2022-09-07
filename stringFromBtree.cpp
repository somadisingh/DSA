#include <iostream>
#include <string>
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
    void dfs(TreeNode *root, string &s)
    {
        if (!root)
            return;
        s += "(";
        s += to_string(root->val);
        dfs(root->left, s);
        if (root->right && root->left == NULL)
            s += "()";
        dfs(root->right, s);
        s += ')';

        return;
    }

public:
    string tree2str(TreeNode *root)
    {
        string s;
        dfs(root, s);
        s.erase(s.begin());
        s.pop_back();
        return s;
    }
};

int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(4);
    Solution s;
    cout << s.tree2str(root) << endl;
    return 0;
}