#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <cmath>

using namespace std;

int main()
{
    int n,m,j;
    cin>>n>>m;
    vector<int>v;
    while(cin>>j) v.push_back(j);
    sort(v.begin(),v.end());
    
    int minsum=INT_MAX,sum=0,i=0;
    while(m>0) {
        sum+=v[i];
        minsum=min(minsum,sum);
        m--;
        i++;
    }
    
    if (minsum<0) cout<<abs(minsum);
    else cout<<0;
    return 0;
}