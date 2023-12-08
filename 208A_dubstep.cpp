//#include <bits/stdc++.h>
#include <iostream>
#include <string>
// https://codeforces.com/problemset/problem/208/A
using namespace std;
// logic: replace WUB with space and print the string. use find function to find WUB in string.
// uske baad replace function use karke WUB ko space se replace kar do.
int main()
{
    string s;
    cin>>s;
    string s1="WUB";
    while(s.find(s1)!=string::npos) s.replace(s.find(s1),3," "); 
    cout<<s;
    return 0;
}

// double space accept karleta hai cf. ye question me kahi mentioned nahi hai but its true.
// is question ne bohot dimaag kharaab kiya bc. simple tha overthink karliya.