/*
Given an array ‘ARR’, partition it into two subsets (possibly empty)
such that their union is the original array. Let the sum of the elements
of these two subsets be ‘S1’ and ‘S2’. Given a difference ‘D’, count the
number of partitions in which ‘S1’ is greater than or equal to ‘S2’ and
the difference between ‘S1’ and ‘S2’ is equal to ‘D’. Since the answer
may be too large, return it modulo ‘10^9 + 7’.
*/

/*
S1 + S2 = total sum of the array
=> let S1 + S2 = totSum
given, S1 - S2 = D
from above 2 equations, D = totSum - 2(S2)
=> S2 = (totSum - D)/2
therefore, with target = S2 find subarrays whose sum = S2
USE THE SAME APPROACH AS COUNT SUBSETS GIVEN SUM DP
 */

#include <iostream>
#include <vector>
using namespace std;

// recursion with memoization
int solve(int index, vector<int> &num, int tar, vector<vector<int>> &dp)
{
    if (index == 0)
    {
        if (tar == 0 && num[index] == 0)
            return 2;
        if (tar == 0 || num[index] == tar)
            return 1;
        return 0;
    }

    if (dp[index][tar] != -1)
        return dp[index][tar];

    int notPick = solve(index - 1, num, tar, dp);
    int pick = 0;
    if (num[index] <= tar)
        pick = solve(index - 1, num, tar - num[index], dp);

    return dp[index][tar] = (pick + notPick) % 1000000007;
}

int findWays(vector<int> &num, int tar)
{
    int n = num.size();
    vector<vector<int>> dp(n, vector<int>(tar + 1, -1));
    return solve(n - 1, num, tar, dp);
}

int countPartitions(int n, int d, vector<int> &arr)
{
    int totalSum = 0;
    for (int i = 0; i < n; i++)
    {
        totalSum += arr[i];
    }
    if (totalSum - d < 0 || (totalSum - d) % 2 != 0)
        return 0;
    return findWays(arr, (totalSum - d) / 2);
}

// tabulation
int findWays(vector<int> &num, int tar)
{
    int n = num.size();
    vector<vector<int>> dp(n, vector<int>(tar + 1, 0));
    if (num[0] == 0)
        dp[0][0] = 2;
    else
        dp[0][0] = 1;

    if (num[0] != 0 && num[0] <= tar)
        dp[0][num[0]] = 1;

    for (int ind = 1; ind < n; ind++)
    {
        for (int sum = 0; sum <= tar; sum++)
        {
            int notTake = dp[ind - 1][sum];
            int take = 0;
            if (num[ind] <= sum)
                take = dp[ind - 1][sum - num[ind]];
            dp[ind][sum] = (take + notTake) % 1000000007;
        }
    }
    return dp[n - 1][tar];
}

int countPartitions(int n, int d, vector<int> &arr)
{
    int totalSum = 0;
    for (int i = 0; i < n; i++)
    {
        totalSum += arr[i];
    }
    if (totalSum - d < 0 || (totalSum - d) % 2 != 0)
        return 0;
    return findWays(arr, (totalSum - d) / 2);
}

// space optimized
int findWays(vector<int> &num, int tar)
{
    int n = num.size();
    vector<int> prev(tar + 1, 0), curr(tar + 1, 0);
    if (num[0] == 0)
        prev[0] = 2;
    else
        prev[0] = 1;

    if (num[0] != 0 && num[0] <= tar)
        prev[num[0]] = 1;

    for (int ind = 1; ind < n; ind++)
    {
        for (int sum = 0; sum <= tar; sum++)
        {
            int notTake = prev[sum];
            int take = 0;
            if (num[ind] <= sum)
                take = prev[sum - num[ind]];
            curr[sum] = (take + notTake) % 1000000007;
        }
        prev = curr;
    }
    return prev[tar];
}

int countPartitions(int n, int d, vector<int> &arr)
{
    int totalSum = 0;
    for (int i = 0; i < n; i++)
    {
        totalSum += arr[i];
    }
    if (totalSum - d < 0 || (totalSum - d) % 2 != 0)
        return 0;
    return findWays(arr, (totalSum - d) / 2);
}