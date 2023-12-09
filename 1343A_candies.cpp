// Link to problem: https://codeforces.com/problemset/problem/1343/A
/* logic: use geometric progression to check the answer. x(2^i - 1) = n. Iterate for k from
2 to 29 and fro every k check if n%((2^k)-1)==0. If yes then return n/((2^k)-1).
*/

#include <iostream>
#include <cmath>

using namespace std;
using ll = long long;

ll calculate(ll n)
{
    for (int i=2; i<=29; i++) {
        ll cal = pow(2,i) - 1;
        if (n%cal==0) {
            return n/cal;
            break;
        }
    }

    return 0;
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
