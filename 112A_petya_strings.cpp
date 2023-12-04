/*
Little Petya loves presents. His mum bought him two 
strings of the same size for his birthday. The strings 
consist of uppercase and lowercase Latin letters. 
Now Petya wants to compare those two strings lexicographically. 
The letters' case does not matter, that is an uppercase 
letter is considered equivalent to the corresponding lowercase 
letter. Help Petya perform the comparison.

Input
Each of the first two lines contains a bought string. 
The strings' lengths range from 1 to 100 inclusive. 
It is guaranteed that the strings are of the same length 
and also consist of uppercase and lowercase Latin letters.

Output
If the first string is less than the second one, print "-1". 
If the second string is less than the first one, print "1". 
If the strings are equal, print "0". Note that the letters' 
case is not taken into consideration when the strings are compared.

Examples

input
aaaa
aaaA
output
0

input
abs
Abz
output
-1

input
abcdefg
AbCdEfF
output
1
LOGIC: Convert both strings to lowercase and then use .compare() method to compare them.

*/

#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>

using namespace std;

int main()
{
    string s1, s2;
    cin>>s1>>s2;
    transform(s2.begin(), s2.end(), s2.begin(), ::tolower);
    transform(s1.begin(), s1.end(), s1.begin(), ::tolower);
    int res = s1.compare(s2);
    if (res==0) cout<<0;
    else if (res<0) cout<<-1;
    else cout<<1;
    return 0;
}