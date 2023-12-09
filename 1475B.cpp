// bool calculate(l n) {
//     if (n==0) return 1;
//     else if (n<0) return 0;
    
//     bool res = calculate(n-2021)+calculate(n-2020);
    
//     return res;
// }

// int main()
// {
//     l t;
//     cin>>t;
//     for (l i=0; i<t; i++) {
//         l n;
//         cin>>n;
//         bool ans=calculate(n);
//         if (ans) cout<<"YES"<<endl;
//         else cout<<"NO"<<endl;
//     }
//     return 0;
// }

// TC: O(2^N)

// Dynamic Programming optimized solution. TC: O(N)

// #include <iostream>
// #include <vector>

// using namespace std;
// using l = long;

// bool calculate(l n,vector<int>dp) {
//     if (n==0) return dp[n]=1;
//     else if (n<0) return 0;
    
//     dp[n] = calculate(n-2021,dp)+calculate(n-2020,dp);
    
//     return dp[n];
// }

// int main()
// {
//     l t;
//     cin>>t;
//     for (l i=0; i<t; i++) {
//         l n;
//         cin>>n;
//         vector<int>dp(n+1);
//         bool ans=calculate(n,dp);
//         if (ans) cout<<"YES"<<endl;
//         else cout<<"NO"<<endl;
//     }
//     return 0;
// }

//implementation
#include <iostream>

using namespace std;
using ll=long long;

bool calculate(ll x)
{
    bool ans=0;
    while(x>0) {
        if (x%2020==0 || x%2021==0){
            ans=1;
            break;
        }
        x-=2021;
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
        bool ans=calculate(n);
        if (ans) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}

// TC: O(N)
/*logic: while loop chalado and har loop me check karo ki number divisible hai 2020 ya 2021 se
agar hai to return true. then subtract karo 2021 se. initially bool = false rakho. 
reason yahi hai ki agar koi number true hai to 2021 se subtract karte karte eventually
divisible hojayega 2020 ya 2021 se. agar number 0 se chota hojata hai to false return kardo.
*/

// https://codeforces.com/problemset/problem/1475/B