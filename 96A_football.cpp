#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s;
    cin>>s;
    int players=1;
    char counter=s[0];
    string ans="NO";
    
    for (int i = 1; i<s.length(); i++) {
        char c=s[i];
        if (c==counter) {
            players++;
            if (players==7) ans="YES";
        }
        else {
            counter=c;
            players=1;
        }
    }
    
    cout<<ans;
    return 0;
}