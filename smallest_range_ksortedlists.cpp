#include <bits/stdc++.h>

using namespace std;

class node
{
public:
    int data;
    int row;
    int col;

    node(int data, int row, int col)
    {
        this->data = data;
        this->row = row;
        this->col = col;
    }
};

class compare
{
public:
    bool operator()(node *a, node *b)
    {
        return a->data > b->data;
    }
};

int kSorted(vector<vector<int>> &a, int k, int n)
{
    int mini = INT_MAX, maxi = INT_MIN;
    priority_queue<node *, vector<node *>, compare> minHeap;

    // step 1: create a min heap for starting element of each list and tracking the min and max val
    for (int i = 0; i < k; i++)
    {
        int element = a[i][0];
        maxi = max(maxi, element);
        mini = min(mini, element);
        minHeap.push(new node(element, i, 0));
    }

    int start = mini, end = maxi;

    // process the ranges
    while (!minHeap.empty())
    {
        // fetch the mini from top of heap
        node *temp = minHeap.top();
        mini = temp->data;

        minHeap.pop();

        // range updation
        if (maxi - mini < end - start)
        {
            start = mini;
            end = maxi;
        }

        // does the next element exist?

        // YES
        if (temp->col + 1 < n)
        {
            maxi = max(maxi, a[temp->row][temp->col + 1]);
            minHeap.push(new node(a[temp->row][temp->col + 1], temp->row, temp->col + 1));
        }

        // NO
        else
            break;
    }

    // answer: difference of range
    return (end - start + 1);
}