#include <iostream>
#include <vector>
#include <algorithm>
/*Ye question ne bewakoof banaya. kaafi aasaan hai. bas simple sort karna hai sab integers
input lekr. Isme idk why I thought trapping rainwater lagega, befaaltu me complicate kiya
fir problem ki rating dekh kar hi realize kiya ki aasaan hai me complicate karra
link to problem: https://codeforces.com/problemset/problem/405/A */

using namespace std;

int main()
{
    vector<int>v;
    int num,n;
    cin>>n;
    while(std::cin>>num) v.push_back(num);
    sort(v.begin(), v.end());
    for (int i:v) cout<<i<<" ";
}