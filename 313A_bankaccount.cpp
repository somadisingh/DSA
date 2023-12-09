#include <iostream>
#include <string>

using namespace std;

int main()
{
    long n;
    cin>>n;
    if (n>=0) cout <<n;
    else {
        string s1 = to_string(n);
        string s2 = to_string(n);
        int x=s1.length();
        // removing last digit
        s1=s1.substr(0,s1.length()-1);
        // removing second-last digit
        char c = s2[x-1];
        s2=s2.substr(0,s2.length()-2);
        s2.append(1,c);
        long new1 = stoi(s1);
        long new2 = stoi(s2);
        if (new1>new2) cout << new1;
        else cout << new2;
    }
    
}