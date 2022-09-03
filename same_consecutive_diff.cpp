#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> ans;
    void helper(int n, int k, int num, int cnt)
    {
        if (cnt == n)
        {
            ans.push_back(num);
            return;
        }
        for (int d = 0; d < 10; d++)
        {
            if (abs(num % 10 - d) == k)
                helper(n, k, num * 10 + d, cnt + 1);
        }
        if (num < 9)
            helper(n, k, num + 1, cnt);

        return;
    }
    vector<int> numsSameConsecDiff(int n, int k)
    {
        helper(n, k, 1, 1);
        return ans;
    }
};

// int begin = pow(10,n-1);
// int end = pow(10, n);
// vector<int>ans;
// for (int i = begin; i < end; i++) {
//     bool flag = 1;
//     int number = i;
//     for (int j = 1; j < n; j++) {
//         int digit1 = number % 10;
//         number /= 10;
//         int digit2 = number%10;
//         if (abs(digit1-digit2) != k) flag = 0;
//     }
//     if (flag == 1) ans.push_back(i);
// }
// return ans;