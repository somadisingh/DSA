#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int bagOfTokensScore(vector<int> &tokens, int power)
    {

        int pts = 0, maxPts = 0, i = 0, j = tokens.size() - 1;
        sort(tokens.begin(), tokens.end());
        while (i <= j)
        {
            if (power >= tokens[i])
            {
                pts++, maxPts = max(pts, maxPts), power -= tokens[i++];
            }
            else if (pts > 0)
            {
                pts--, power += tokens[j--];
            }
            else
                return maxPts;
        }
        return maxPts;
    }
};