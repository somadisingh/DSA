/*
An integer array original is transformed into a doubled array changed
by appending twice the value of every element in original, and then
randomly shuffling the resulting array.

Given an array changed, return original if changed is a doubled array.
If changed is not a doubled array, return an empty array. The elements
in original may be returned in any order.

Example 1:

Input: changed = [1,3,4,2,6,8]
Output: [1,3,4]
Explanation: One possible original array could be [1,3,4]:
- Twice the value of 1 is 1 * 2 = 2.
- Twice the value of 3 is 3 * 2 = 6.
- Twice the value of 4 is 4 * 2 = 8.
Other original arrays could be [4,3,1] or [3,1,4].

*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution
{
public:
    vector<int> findOriginalArray(vector<int> &changed)
    {

        vector<int> ans;
        if (changed.size() % 2 != 0)
            return ans;

        unordered_map<int, int> mat;

        for (int i = 0; i < changed.size(); i++)
        {
            mat[changed[i]]++;
        }
        sort(changed.begin(), changed.end());

        for (int i = 0; i < changed.size(); i++)
        {
            int j = changed[i];
            if (mat[j] > 0)
            {
                if (mat[2 * j] > 0)
                {
                    mat[j]--;
                    mat[2 * j]--;
                    ans.push_back(j);
                }
                else
                {
                    vector<int> temp;
                    return temp;
                }
            }
        }
        return ans;
    }
};