#include <iostream>

using namespace std;
using ll=long long;

ll calculate(ll x)
{
    ll ans=0;
    while(x>1) {
        if (x%6==0) x/=6;
        else if ((x*2)%6==0) x*=2;
        else {
            ans=-1;
            break;
        }
        ans++;
    }
    return ans;
}


int main()
{
    ll t;
    cin>>t;
    for (ll i=0; i<t; i++) {
        ll n;
        cin>>n;
        ll ans=calculate(n);
        cout<<ans<<endl;
    }
    return 0;
}
