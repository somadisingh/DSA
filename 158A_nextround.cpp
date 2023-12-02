/*
"Contestant who earns a score equal to or greater than the k-th place 
finisher's score will advance to the next round, as long as the 
contestant earns a positive score..." — an excerpt from contest rules.

A total of n participants took part in the contest (n ≥ k), and you 
already know their scores. Calculate how many participants will 
advance to the next round.

Input
The first line of the input contains two integers n and k (1 ≤ k ≤ n ≤ 50) 
separated by a single space.

The second line contains n space-separated integers a1, a2, ..., an (0 ≤ ai ≤ 100), 
where ai is the score earned by the participant who got the i-th place. 
The given sequence is non-increasing (that is, for all i from 1 to n - 1 
the following condition is fulfilled: ai ≥ ai + 1).

Output
Output the number of participants who advance to the next round.

Examples
inputCopy
8 5
10 9 8 7 7 7 5 5
outputCopy
6
inputCopy
4 2
0 0 0 0
outputCopy
0
*/

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    //pehle formality karo; input lo
    int size, bench;
    std::cin>>size>>bench;
    
    std::vector<int>v;
    int num;
    while(std::cin>>num) v.push_back(num);
    
    // condition lagao: case 1: benchmark score<=0
    int bench_score = v[bench-1];
    int ans=0;
    
    if (bench_score<=0) {
        for (int i:v) {
            if (i<=0) break;
            else ans++;
        }
    }
    
    // condition 2: benchmark score>0
    else {
        ans+=bench;
        for (int i = bench-1; i < size; i++) {
            if (v[i]>=bench_score) ans++;
            else break;
        }
        ans-=1;
    }
    
    // answer dikhao bc 
    std::cout<<ans;
    return 0;
}