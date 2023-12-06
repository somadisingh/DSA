/*
A zero corresponds to players of one team; a one corresponds 
to players of another team. If there are at least 7 players 
of some team standing one after another, then the situation 
is considered dangerous. For example, the situation 00100110111111101 
is dangerous and 11110111011101 is not. You are given the current 
situation. Determine whether it is dangerous or not.

Input
The first input line contains a non-empty string consisting of 
characters "0" and "1", which represents players. The length 
of the string does not exceed 100 characters. There's at least 
one player from each team present on the field.

Output
Print "YES" if the situation is dangerous. Otherwise, print "NO".

Examples
input
001001
output
NO

input
1000000001
output
YES

logic yahi hai ki ek counter rekho 0th element par, then start iterating from second element and check if its the same as
its previous element which is the counter. agar hai same to player count badhado aur wahi par ek check daaldo ki agar player count
7 hojaye to answer me yes store karlo aur loop se break karjao. agar same nahi hai to counter ko update kardo to the current element
and player count ko reset kardo back to 1. also before starting the loop answer me no store karlo.
Optimization: if string length is <7 then answer is always no.
*/



#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s;
    cin>>s;

    if (s.length()<7) {
        cout<<"NO";
        return 0;
    }

    int players=1;
    char counter=s[0];
    string ans="NO";
    
    for (int i = 1; i<s.length(); i++) {
        char c=s[i];
        if (c==counter) {
            players++;
            if (players==7) {
                ans="YES";
                break;
            }
        }
        else {
            counter=c;
            players=1;
        }
    }
    
    cout<<ans;
    return 0;
}