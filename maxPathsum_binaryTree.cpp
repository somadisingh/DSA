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
    int findSum(TreeNode *root, int &maxSum)
    {
        if (!root)
            return 0;

        // to account for the negative sum, if a path returns negative sum then dont consider it and send 0
        int leftSum = max(0, findSum(root->left, maxSum));
        int rightSum = max(0, findSum(root->right, maxSum));

        maxSum = max(maxSum, leftSum + rightSum + root->val);

        return root->val + max(leftSum, rightSum);
    }

public:
    int maxPathSum(TreeNode *root)
    {

        int sum = -1e9;
        findSum(root, sum);
        return sum;
    }
};