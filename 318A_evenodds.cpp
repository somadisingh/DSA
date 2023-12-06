/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;

// use long long shorthand cause long aint enough for this problem
using ll = long long;

int main()
{
    ll n,k;
    //n hai wo number jisme 1 to n odd then 1 to n even arranged hai. k hai position. pehle input liya jaye
    cin>>n>>k;
    
    // do cases banenge. case 1 is when n is even no. ye simple hai;
    if (n%2==0) {
        /*arithmetic sequence ka formula An = a + (n-1)d => a=1 ye a=2 will depend on k. agar 
        k odd territory me hai then a=1 else a=2.*/
        ll a,d=2;
        /*isme further 2 cases: first is when the no. we want to locate falls in odd territory, then 
        secon is when it falls in even territory*/
        if(k<=n/2) a=1;
        else {
            a=2;
            k-=(n/2);
        }
        
        ll An = a+((k-1)*d);
        cout<<An;
    }
    
    // ab aata hai when n is odd, isme har case me odd no. ki frequency even no. se ek zyada hogi. 
    else {
        ll a,d=2;
        /* +1 kiya cause odd no ek zyada hai even se. isme bhi do case, 1 is when the no. we are looking
         for falls in the odd territory*/
        if(k<=(n/2)+1) a=1;
        // when the no. we are looking for falls in even territory.
        else {
            // k ka bhi value change karna hoga accordingly cause even no. me restart hoga counting
            a=2;
            k-=((n/2)+1);
        }
        
        ll An = a+((k-1)*d);
        cout<<An;
    }
    

    return 0;
}
