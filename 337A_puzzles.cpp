#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
// https://codeforces.com/problemset/problem/337/A
using namespace std;

int main()
{
    // pehle input lo. n is students, m is puzzles and vector me number of pieces per puzzle aata hai.
    int n,m,num;
    cin>>n>>m;
    vector<int>v;
    while(cin>>num) v.push_back(num);
    sort(v.begin(),v.end());
    // i guess sort karna zaroori hai cause minimum difference ka zyada chance aaspaas ke number me hai.
    
    // ab karte hai calculate sliding window use karke. 
    /*window size is basically no. of students and har window me sabse chhota aur
    sabse bada integer nikal kar unka difference calculate krenge aur minimum
    difference store karenge diffinal me aur har window ke iteration par diffinal
    ko update karte rahenge.*/
    int diffinal=INT_MAX,start=0,j=n-1;
    while(j<m) {
        int maxi=INT_MIN,mini=INT_MAX;
        for(int i=start; i<=j; i++) {
            maxi=max(v[i],maxi);
            mini=min(v[i],mini);
        }
        int diff=maxi-mini;
        diffinal=min(diff,diffinal);
        start++;
        j++;
    }
    cout<<diffinal;
    return 0;
}