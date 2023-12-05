/*
There are n stones on the table in a row, each of them can be red, 
green or blue. Count the minimum number of stones to take from the 
table so that any two neighboring stones had different colors. 
Stones in a row are considered neighboring if there are no other stones between them.

Input
The first line contains integer n (1 ≤ n ≤ 50) — the number of stones on the table.

The next line contains string s, which represents the colors of the 
stones. We'll consider the stones in the row numbered from 1 to n from 
left to right. Then the i-th character s equals "R", if the i-th stone
 is red, "G", if it's green and "B", if it's blue.


Output
Print a single integer — the answer to the problem.

Examples
input
3
RRG
output
1
input
5
RRRRR
output
4
input
4
BRBG
output
0

*/


#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s;
    int n;
    cin>>n>>s;
    if (s.length()==1) cout << 0;
    else {
        char counter=s[0];
        int rem=0;
        for (int i = 1; i < s.length(); i++) {
            char c = s[i];
            if (c==counter) {
                rem++;
            }
            else counter = c;
        }
        cout<<rem;
    }
    
    

    return 0;
}
