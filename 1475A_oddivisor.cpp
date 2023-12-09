/*
You are given an integer n
. Check if n
 has an odd divisor, greater than one (does there exist 
 such a number x (x>1) that n is divisible by x and x is odd).

For example, if n=6, then there is x=3. If n=4, then such a number does not exist.

Input
The first line contains one integer t (1≤t≤104) — the number of test cases. Then t test cases follow.

Each test case contains one integer n (2≤n≤1014).

Please note, that the input for some test cases won't fit into 32
-bit integer type, so you should use at least 64
-bit integer type in your programming language.

Output
For each test case, output on a separate line:

"YES" if n has an odd divisor, greater than one;
"NO" otherwise.
You can output "YES" and "NO" in any case (for example, the strings yEs, yes, Yes and YES will be recognized as positive).
*/

#include <iostream>
#include <string>
using ll = long long;
using namespace std;

string calculate(ll n) {
    //case 1: agar integer 1 hai to return no.
    if (n==1) return "NO";
    //case 2: agar integer odd hai to return kardo yes
    else if (n%2!=0) return "YES";
    //case 3: agar integer even hai to number tabtak 2 se divide karte raho jabtak odd digit nai aata
    string ans="NO";
    while(n%2==0) {
        n/=2;
        if (n%2!=0 && n!=1) ans="YES";
    }
    return ans;
}

// WORST CASE TC: O(logN)

int main()
{
    ll t;
    cin>>t;
    for (ll i=0; i<t; i++) {
        ll n;
        cin>>n;
        string ans=calculate(n);
        cout<<ans<<endl;
    }
    return 0;
}

// TC: O(1)

/*logic: 3 cases banege. c1 is ki number 1 hai tab to answer no hai. case 2 is when
the number is odd then the answer is yes and case 3 when number is even tab fir
2 se divide karke check karte raho jab tak koi odd number nai aata ya fir number
1 par terminate nai hota. agar 1 par khatam hota hai then answer is no else yes*/