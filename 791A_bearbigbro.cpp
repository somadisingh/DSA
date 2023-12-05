
/*
Right now, Limak and Bob weigh a and b respectively. It's guaranteed that 
Limak's weight is smaller than or equal to his brother's weight.

Limak eats a lot and his weight is tripled after every year,
 while Bob's weight is doubled after every year.

After how many full years will Limak become strictly larger (strictly heavier) than Bob?

Input
The only line of the input contains two integers a and b (1 ≤ a ≤ b ≤ 10) — 
the weight of Limak and the weight of Bob respectively.

Output
Print one integer, denoting the integer number of years after which
 Limak will become strictly larger than Bob.

Examples
input
4 7
output
2
input
4 9
output
3
*/


#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    double a,b,calc;
    cin>>a>>b;
    double t = b/a;
    calc = log(t)/log(1.5);
    calc++;
    int ans = static_cast<int>(calc);
    cout<<ans;
    return 0;
}