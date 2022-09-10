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
            if (i == 0 || j == 0) // base case included here
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

// tabulation another way

int longestCommonSubsequence(string text1, string text2)
{
    int m = text1.length();
    int n = text2.length();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    // base case already included in the initialization of dp
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (text1[i - 1] == text2[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    return dp[m][n];
}

/* ALTERNATIVE APPROACH
    for (int j = 1; j <= n; j++) {
                int notMatch = max(dp[i-1][j], dp[i][j-1]);
                int match = 0;
                if (s1[i-1] == s2[j-1]) match = 1 + dp[i-1][j-1];
                dp[i][j] = max(match, notMatch);
        }
    }
    return dp[m][n];
*/

// space optimized

int longestCommonSubsequence(string text1, string text2)
{
    int m = text1.length();
    int n = text2.length();
    vector<int> prev(n + 1, 0), curr(n + 1, 0);

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (text1[i - 1] == text2[j - 1])
                curr[j] = 1 + prev[j - 1];

            else
                curr[j] = max(prev[j], curr[j - 1]);
        }
        prev = curr;
    }
    return prev[n];
}

// print lcs

void printLCS(string s1, string s2)
{
    int m = s1.length();
    int n = s2.length();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (s1[i - 1] == s2[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    string ans = "";
    int i = m, j = n;
    while (i > 0 && j > 0)
    {
        if (s1[i - 1] == s2[j - 1])
        {
            ans += s1[i - 1];
            i--;
            j--;
        }
        else
        {
            if (dp[i - 1][j] > dp[i][j - 1])
                i--;
            else
                j--;
        }
    }
    reverse(ans.begin(), ans.end());
    cout << ans << endl;
}