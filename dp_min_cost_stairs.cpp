#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int solve(vector<int> &cost, int n, vector<int> &dp)
    {
        // base case
        if (n == 0)
            return cost[0];
        if (n == 1)
            return cost[1];

        // check if recurring subproblem has occured already or not
        if (dp[n] != -1)
            return dp[n];

        dp[n] = cost[n] + min(solve(cost, n - 1, dp), solve(cost, n - 2, dp));
        return dp[n];
    }

    int minCostClimbingStairs(vector<int> &cost)
    {
        int n = cost.size();
        vector<int> dp(n + 1, -1);
        int ans;
        ans = min(solve(cost, n - 1, dp), solve(cost, n - 2, dp));
        return ans;
    }
};

// int n = cost.size(); TABULATION METHOD
//         vector<int>dp(n+1,-1);
//         dp[0]=cost[0];
//         dp[1]=cost[1];
//         for (int i = 2; i < n; i++) {
//             dp[i]=cost[i]+min(dp[i-1], dp[i-2]);
//         }

//         int ans;
//         ans = min(dp[n-1], dp[n-2]);
//         return ans;

// int n = cost.size(); CONSTANT SPACE METHOD
// int prev1=cost[0];
// int prev2=cost[1];
// for (int i = 2; i < n; i++) {
//     int ans = cost[i] + min(prev1, prev2);
//     prev1=prev2;
//     prev2=ans;
// }
// return min(prev1,prev2);