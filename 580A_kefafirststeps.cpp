#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int>v;
    int num,n;
    cin>>n;
    while(std::cin>>num) v.push_back(num);
    if (v.size()==1) {
        cout << 1;
        return 0;
    }
    
    int counter=v[0], profit=1,maxprofit=0;
    for(int i=1; i<n; i++) {
        int compare=v[i];
        if (compare>=counter) profit++;
        else profit=1;
        counter=compare;
        maxprofit=max(profit,maxprofit);
    }
    cout<<maxprofit;
}
