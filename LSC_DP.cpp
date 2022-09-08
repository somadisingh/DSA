#include <iostream>
#include <vector>

using namespace std;

// recursion and memoization
class Solution
{
public:
    int lcs(int ind1, int ind2, string &s1, string &s2, vector<vector<int>> &dp)
    {
        if (ind1 < 0 || ind2 < 0)
        {
            return 0;
        }

        if (dp[ind1][ind2] != -1)
            return dp[ind1][ind2];

        int match = 0;
        if (s1[ind1] == s2[ind2])
            match = 1 + lcs(ind1 - 1, ind2 - 1, s1, s2, dp);

        int notMatch = max(lcs(ind1 - 1, ind2, s1, s2, dp), lcs(ind1, ind2 - 1, s1, s2, dp));

        return dp[ind1][ind2] = max(match, notMatch);
    }

public:
    int longestCommonSubsequence(string text1, string text2)
    {
        int m = text1.length();
        int n = text2.length();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return lcs(m - 1, n - 1, text1, text2, dp);
    }
};

// tabulation
int longestCommonSubsequence(string text1, string text2)
{
    int m = text1.length();
    int n = text2.length();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (i == 0 || j == 0) // base case
                dp[i][j] = 0;
            else
            { // recusrive case
                int match = 0;
                if (text1[i - 1] == text2[j - 1])
                    match = 1 + dp[i - 1][j - 1];

                int notMatch = max(dp[i - 1][j], dp[i][j - 1]);

                dp[i][j] = max(match, notMatch);
            }
        }
    }
    return dp[m][n];
}