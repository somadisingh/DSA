#include <iostream>
#include <stack>
using namespace std;

void deleteMiddle(stack<int> &inputStack, int N)
{

    int x = N / 2;
    stack<int> s;
    while (x != 0)
    {
        int i = inputStack.top();
        inputStack.pop();
        x--;
        s.push(i);
    }
    inputStack.pop();

    while (!s.empty())
    {
        int i = s.top();
        s.pop();
        x--;
        inputStack.push(i);
    }
}