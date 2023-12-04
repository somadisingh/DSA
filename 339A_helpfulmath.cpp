/*
The teacher has written down the sum of multiple numbers. Pupils 
should calculate the sum. To make the calculation easier, the 
sum only contains numbers 1, 2 and 3. Still, that isn't enough for 
Xenia. She is only beginning to count, so she can calculate a sum 
only if the summands follow in non-decreasing order. For example, 
she can't calculate sum 1+3+2+1 but she can calculate sums 1+1+2 and 3+3.

You've got the sum that was written on the board. Rearrange the summans
 and print the sum in such a way that Xenia can calculate the sum.

Input
The first line contains a non-empty string s — the sum Xenia needs to count. 
String s contains no spaces. It only contains digits and characters "+". 
Besides, string s is a correct sum of numbers 1, 2 and 3. String s is at most 100 characters long.

Output
Print the new sum that Xenia can count.

Examples

input
3+2+1
output
1+2+3

input
1+1+3+1+3
output
1+1+1+3+3

input
2
output
2
*/

#include <iostream>
#include <string>

using namespace std;

int main()
{
    // pehle tum 1, 2 aur 3 ka frequency calculate karo string me 
    string s;
    cin>>s;
    int one=0, two=0, three=0;
    for (char c: s) {
        if (c=='1') one++;
        else if (c=='2') two++;
        else if (c=='3') three++;
        else continue;
    }
    // ab ek naya string banao jisme order wise daalo tum apna 1, 2 aur 3 
    string ans = "";
    for (int i=0; i< one; i++) {
        ans+="1+";
    }
    for (int i=0; i< two; i++) {
        ans+="2+";
    }
    for (int i=0; i< three; i++) {
        ans+="3+";
    }
    
    ans=ans.substr(0,ans.size()-1);
    cout<<ans;

    return 0;
}