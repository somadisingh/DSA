#include "bits/stdc++.h"

using namespace std;

string longestCommonPrefix(vector<string> &arr, int n)
{
    string ans = "";
    // traverse characters of the first string
    for (int i = 0; i < arr[0].length(); i++)
    {
        char ch = arr[0][i];
        bool match = true;

        // compare ch with rest of the strings
        for (int j = 1; j < n; j++)
        {
            if (arr[j].size() < i || ch != arr[j][i])
            { // if character doesn't match or if size exceeds
                match = false;
                break;
            }
        }
        if (match == false)
            break;
        else
            ans.push_back(ch);
    }
    return ans;
}