#include <iostream>
// https://codeforces.com/problemset/problem/451/A
using namespace std;

/*logic: calculate no. of intersections and run a while loop.
now at every iteration remove all intersections which will be removed 
as a result of removing just one, update the total intersections and store in the bool variable the person
whose chance it is. after the loop is over the bool will store the person who played the 
last chance. that is your answer */

int main()
{
    int n,m;
    cin>>n>>m;
    int intersec=m*n;
    bool flag=0;
    while(intersec>0) {
        intersec-=(m+n-1);
        m-=1;
        n-=1;
        flag=!flag;
    }
    if (flag) cout << "Akshat";
    else cout << "Malvika";
    return 0;
}
