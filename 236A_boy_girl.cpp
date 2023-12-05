/*
This is his method: if the number of distinct characters in one's user name 
is odd, then he is a male, otherwise she is a female. You are given the string 
that denotes the user name, please help our hero to determine the gender of this user by his method.

Input
The first line contains a non-empty string, that contains only lowercase 
English letters — the user name. This string contains at most 100 letters.

Output
If it is a female by our hero's method, print "CHAT WITH HER!" (without the quotes), 
otherwise, print "IGNORE HIM!" (without the quotes).

Examples

input
wjmzbmr
output
CHAT WITH HER!

input
xiaodao
output
IGNORE HIM!

input
sevenkplus
output
CHAT WITH HER!

logic: string iterate karke set me sab daaldo aur set ka size dekhlo.
*/

#include <iostream>
#include <string>
#include <set>

using namespace std;

int main()
{
    string s;
    cin>>s;
    set<char>dis;
    for (char c: s) dis.insert(c);
    if (dis.size()%2==0) cout << "CHAT WITH HER!";
    else cout<< "IGNORE HIM!";
    
    

    return 0;
}