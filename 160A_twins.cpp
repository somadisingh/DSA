#include <iostream>
#include <vector>
#include <algorithm>
// problem statement too long, refer to: https://codeforces.com/problemset/problem/160/A
/*logic is pehle input ko vector me lekar descending order me sort kardo. 
then ek max=0 delcare karke har iteration me sum add karte jao and at the same time
us sum ko remaining elements se subtract karke difference lo. jis iteration me sum>difference, wha break kardo and wo iteration no. print kardo*/
using namespace std;

int main()
{
    int n,tot=0;
    cin>>n;
    vector<int>v(n);
    for (int i=0; i<n; i++) {
        int x;
        cin>>x;
        v.push_back(x);
        tot+=x;
    }
    
    sort(v.begin(),v.end(),greater<int>());
    int max=0, left;
    for (int i=0; i<n; i++) {
        max+=v[i];
        left=tot-max;
        if (max>left) {
            cout<<i+1;
            break;
        }
    }

    return 0;
}