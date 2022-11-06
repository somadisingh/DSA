#include <bits/stdc++.h>
using namespace std;

template <typename T>
class TreeNode
{
public:
    T val;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T val)
    {
        this->val = val;
        left = NULL;
        right = NULL;
    }
};

vector<int> getTopView(TreeNode<int> *root)
{
    vector<int> ans;
    if (!root)
        return ans;
    map<int, int> m;
    queue<pair<TreeNode<int> *, int>> q;
    q.push({root, 0});
    while (!q.empty())
    {
        auto x = q.front();
        q.pop();
        TreeNode<int> *node = x.first;
        int y = x.second;
        if (m.find(y) == m.end())
            m[y] = node->val;

        if (node->left)
            q.push({node->left, y - 1});
        if (node->right)
            q.push({node->right, y + 1});
    }

    for (auto x : m)
    {
        ans.push_back(x.second);
    }
    return ans;
}

int main()
{
    TreeNode<int> *root = new TreeNode<int>(1);
    root->left = new TreeNode<int>(2);
    root->right = new TreeNode<int>(3);
    root->left->right = new TreeNode<int>(4);
    root->left->right->right = new TreeNode<int>(5);
    root->left->right->right->right = new TreeNode<int>(6);
    vector<int> ans = getTopView(root);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
}