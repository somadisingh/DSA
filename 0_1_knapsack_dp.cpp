#include <bits/stdc++.h>
using namespace std;

//  solution using recursion and memoization
//  Time Complexity: O(N)
//  Space Complexity: O(N) + Space taken by recursion stack

int solve(vector<int> weight, vector<int> value, int item, int capacity, vector<vector<int>> &dp)
{
    // base case: last item has been reached
    if (item == 0)
    {
        if (weight[0] <= capacity)
            return value[0];
        else
            return 0;
    }

    // memoization fetch
    if (dp[item][capacity] != -1)
        return dp[item][capacity];

    // recursive relation: include item
    int include = 0;
    if (weight[item] <= capacity)
    {
        include = value[item] + solve(weight, value, item - 1, capacity - weight[item], dp);
    }
    int exclude = solve(weight, value, item - 1, capacity, dp);

    // memoization
    dp[item][capacity] = max(include, exclude);
    return dp[item][capacity];
}

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight)
{
    vector<vector<int>> dp(n, vector<int>(maxWeight + 1, -1));
    int res = solve(weight, value, n - 1, maxWeight, dp);
    return res;
}

// int main()
{
    int n, maxWeight;
    cin >> n >> maxWeight;
    vector<int> weight(n), value(n);
    for (int i = 0; i < n; i++)
    {
        cin >> weight[i] >> value[i];
    }
    cout << knapsack(weight, value, n, maxWeight) << endl;
    return 0;
}

// solution using tabulation
// Time Complexity: O(N)
// Space Complexity: O(N*MaxWeight)

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight)
{
    // step 1: initialize dp table
    vector<vector<int>> dp(n, vector<int>(maxWeight + 1, 0));

    // step 2: analyze base case
    for (int w = weight[0]; w <= maxWeight; w++)
    {
        if (weight[0] <= maxWeight)
            dp[0][w] = value[0];
        else
            dp[0][w] = 0;
    }

    // step 3: convert recursive relation to tabulation & for loop
    for (int index = 1; index < n; index++)
    {
        for (int w = 0; w <= maxWeight; w++)
        {
            int include = 0;
            if (weight[index] <= w)
            {
                include = value[index] + dp[index - 1][w - weight[index]];
            }
            int exclude = dp[index - 1][w];
            dp[index][w] = max(include, exclude);
        }
    }
    return dp[n - 1][maxWeight];
}

// OPTIMIZED SOLUTION
// Space Complexity: O(2*MaxWeight)

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight)
{
    vector<int> prev(maxWeight + 1, 0);
    vector<int> curr(maxWeight + 1, 0);

    for (int w = weight[0]; w <= maxWeight; w++)
    {
        if (weight[0] <= maxWeight)
            prev[w] = value[0];
        else
            prev[w] = 0;
    }

    for (int index = 1; index < n; index++)
    {
        for (int w = 0; w <= maxWeight; w++)
        {
            int include = 0;
            if (weight[index] <= w)
                include = value[index] + prev[w - weight[index]];
            int exclude = prev[w];
            curr[w] = max(include, exclude);
        }
        prev = curr;
    }
    return prev[maxWeight];
}

// Further Optimized
//  Space Complexity: O(MaxWeight)
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight)
{

    vector<int> curr(maxWeight + 1, 0);

    for (int w = weight[0]; w <= maxWeight; w++)
    {
        if (weight[0] <= maxWeight)
            curr[w] = value[0];
        else
            curr[w] = 0;
    }

    for (int index = 1; index < n; index++)
    {
        for (int w = maxWeight; w >= 0; w--)
        {
            int include = 0;
            if (weight[index] <= w)
                include = value[index] + curr[w - weight[index]];
            int exclude = curr[w];
            curr[w] = max(include, exclude);
        }
    }
    return curr[maxWeight];
}