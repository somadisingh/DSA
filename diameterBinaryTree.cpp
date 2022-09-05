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
    int findDiameter(TreeNode *root, int &maxi)
    {
        if (root == NULL)
            return 0;

        int left = findDiameter(root->left, maxi);
        int right = findDiameter(root->right, maxi);

        maxi = max(maxi, left + right);

        return 1 + max(left, right);
    }

public:
    int diameterOfBinaryTree(TreeNode *root)
    {

        int maxi = 0;
        findDiameter(root, maxi);
        return maxi;
    }
};