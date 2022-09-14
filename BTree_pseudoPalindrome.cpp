#include <iostream>
#include <map>

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
    bool isPal(map<int, int> &freq)
    {
        int cnt = 0; // count of odd freq occurances
        for (auto i : freq)
        {
            if (i.second % 2 != 0) // if odd freq occurances found then increment cnt
                cnt++;
        }
        if (cnt == 0 || cnt == 1) // if even freq occurances or only one odd freq occurance then return true
            return true;
        else
            return false;
    }

public:
    int dfs(TreeNode *root, map<int, int> &freq)
    {
        if (!root)
            return 0;
        if (!root->left && !root->right) // if leaf node
        {
            freq[root->val]++; // add the value to the map
            if (isPal(freq))   // check if map is palindrome
            {
                freq[root->val]--; // YES? remove the value's occurance from the map and return 1
                return 1;
            }
            else
            {
                freq[root->val]--; // NO? remove the value's occurence from the map and return 0
                return 0;
            }
        }

        freq[root->val]++; // increment the value's occurence in the map

        int left = dfs(root->left, freq);
        int right = dfs(root->right, freq);

        freq[root->val]--; // Backtrack: decrement the value's occurence in the map

        return left + right; // return the sum of left and right subtree: this is the number of pseudo-palindromic paths
    }

public:
    int pseudoPalindromicPaths(TreeNode *root)
    {

        /*
        do a dfs traversal of the b tree and count the elements of a path. If the
        frequency of elements occuring is even then the path can be rearranged to form palindrome
        else if the frequency is odd, the atmost 1 elemnt should have odd frequency and rest even
        */
        map<int, int> freq;
        return dfs(root, freq);
    }
};