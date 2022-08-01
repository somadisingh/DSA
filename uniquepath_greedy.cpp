#include <bits/stdc++.h>
using namespace std;

class Solution
{

public:
    int traverse(int x, int y, int m, int n)
    {

        if (x == m - 1 && y == n - 1)
            return 1;
        if (x > m - 1 || y > n - 1)
            return 0;

        return traverse(x + 1, y, m, n) + traverse(x, y + 1, m, n);
    }

public:
    int uniquePaths(int m, int n)
    {

        int ans = traverse(0, 0, m, n);
        return ans;
    }
};