#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007

//  solution using recursion and memoization
//  Time Complexity: O(N)
//  Space Complexity: O(N) + Space taken by recursion stack
int add(int a, int b)
{
    return (a % MOD + b % MOD) % MOD;
}

int multiply(int a, int b)
{
    return ((a % MOD) * 1LL * (b % MOD)) % MOD;
}

int solve(int n, int k, vector<int> &dp)
{
    // base case
    if (n == 1)
        return k;
    if (n == 2)
        return add(k, multiply(k, k - 1));
    // memoization
    if (dp[n] != -1)
        return dp[n];
    // recursive relation
    dp[n] = add(multiply(solve(n - 2, k, dp), k - 1), multiply(solve(n - 1, k, dp), k - 1));
    return dp[n];
}

int numberOfWays(int n, int k)
{
    vector<int> dp(n + 1, -1);
    return solve(n, k, dp);
}

// solution using tabulation
// Time Complexity: O(N)
// Space Complexity: O(N)
int numberOfWays(int n, int k)
{

    vector<int> dp(n + 1, 0);
    dp[1] = k;
    dp[2] = add(k, multiply(k, k - 1));
    for (int i = 3; i <= n; i++)
    {
        dp[i] = add(multiply(dp[i - 2], k - 1), multiply(dp[i - 1], k - 1));
    }
    return dp[n];
}

// space complexity O(1)
// dp[i] depends on 2 variables, dp[i-1] and dp[i-2] hence O(1) solution is possible
int numberOfWays(int n, int k)
{
    int prev2 = k;
    int prev1 = add(k, multiply(k, k - 1));
    for (int i = 3; i <= n; i++)
    {
        int ans = add(multiply(prev2, k - 1), multiply(prev1, k - 1));
        prev2 = prev1;
        prev1 = ans;
    }
    return prev1;
}