#include <iostream>
#include <vector>

using namespace std;

int calculate(int kx, int ky, int kingx, int kingy, int queenx, int queeny)
{
    //prepare helper array to calculate the knight moves
    vector<pair<int,int>>v;
    v.push_back(make_pair(kx,ky));
    v.push_back(make_pair(kx,-ky));
    v.push_back(make_pair(-kx,-ky));
    v.push_back(make_pair(-kx,ky));
    v.push_back(make_pair(ky,kx));
    v.push_back(make_pair(ky,-kx));
    v.push_back(make_pair(-ky,-kx));
    v.push_back(make_pair(-ky,kx));
    
    vector<pair<int,int>>k;
    // calculate all possible positions from where knight can attack king and store in array
    for (int i = 0; i < v.size(); i++) {
        int x=kingx+v[i].first;
        int y=kingy+v[i].second;
        pair<int,int>p=make_pair(x,y);
        k.push_back(p);
    }
    /* calculate all possible positions from where knight can attack queen and compare with
    kings coordinates to see if there is a match. a match means that knight can attack both
    king and queen form that position*/
    int ans=0;
    for (int i=0; i<v.size(); i++) {
        int x=queenx+v[i].first;
        int y=queeny+v[i].second;
        for (int j=0; j<k.size(); j++) {
            if (x==k[j].first && y==k[j].second) ans++;
        }
    }
    
    return ans;
}

int main() {
    int kx,ky,kingx,kingy,queenx,queeny,t,n;
    cin>>t;
    for (int i=0; i<t; i++) {
        cin>>kx>>ky;
        cin>>kingx>>kingy;
        cin>>queenx>>queeny;
        int ans=calculate(kx,ky,kingx,kingy,queenx,queeny);
        cout<<ans<<endl;
    }
    return 0;
}
