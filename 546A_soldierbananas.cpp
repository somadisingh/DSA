#include <iostream>

using namespace std;

int main()
{
    int k,n,w;
    cin>>k>>n>>w;
    int tot = (k*w*(w+1))/2;
    if (n>=tot) cout << 0;
    else {
        int ans=tot-n;
        cout<<ans;
    }

    return 0;
}