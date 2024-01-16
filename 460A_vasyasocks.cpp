#include <iostream>

using namespace std;
//using ll = long long;

int main()
{
    int n,m,ans=0;
    cin>>n>>m;
    for (int i=1; i<=n; i++) {
        ans++;
        if (i%m==0) n++;
    }
    cout<<ans;
    return 0;
}

// try mathematically 
