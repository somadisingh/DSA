/*
Maximum Score from Performing Multiplication Operations

You are given two integer arrays nums and multipliers of
size n and m respectively, where n >= m. The arrays are 1-indexed.

You begin with a score of 0. You want to perform exactly m operations.
On the ith operation (1-indexed), you will:

Choose one integer x from either the start or the end of the array nums.
Add multipliers[i] * x to your score.
Remove x from the array nums.
Return the maximum score after performing m operations.

Input: nums = [1,2,3], multipliers = [3,2,1]
Output: 14
Explanation: An optimal solution is as follows:
- Choose from the end, [1,2,3], adding 3 * 3 = 9 to the score.
- Choose from the end, [1,2], adding 2 * 2 = 4 to the score.
- Choose from the end, [1], adding 1 * 1 = 1 to the score.
The total score is 9 + 4 + 1 = 14.
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<vector<int>> dp;
    int solve(int i, int n, int j, vector<int> &nums, vector<int> &multipliers)
    {
        if (j == multipliers.size())
            return 0;
        if (dp[i][j] != INT_MIN)
            return dp[i][j];
        int left = solve(i + 1, n, j + 1, nums, multipliers) + (nums[i] * multipliers[j]);
        int right = solve(i, n, j + 1, nums, multipliers) + (nums[(n - 1) - (j - i)] * multipliers[j]);
        return dp[i][j] = max(left, right);
    }
    int maximumScore(vector<int> &nums, vector<int> &multipliers)
    {
        int n = nums.size(), m = multipliers.size();
        dp.resize(m + 1, vector<int>(m + 1, INT_MIN));
        return solve(0, n, 0, nums, multipliers);
    }
};