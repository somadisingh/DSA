#include <bits/stdc++.h>
using namespace std;

#include <algorithm>
bool compare(vector<int> &a, vector<int> &b) // arrange in ascending order of weights
{
    return (a[2] < b[2]);
}
void makeSet(vector<int> &parent, vector<int> rank, int n) // initialize parent and rank
{
    for (int i = 0; i < n; i++)
    {
        parent[i] = i;
        rank[i] = 0;
    }
}
int findParent(vector<int> &parent, int node) // find parent of a node
{
    if (parent[node] == node)
        return node;
    return parent[node] = findParent(parent, parent[node]);
}
void unionSet(int u, int v, vector<int> &parent, vector<int> &rank) // find rank
{
    u = findParent(parent, u);
    v = findParent(parent, v);

    if (rank[u] > rank[v])
        parent[v] = u;
    else if (rank[v] > rank[u])
        parent[u] = v;
    else
    {
        parent[v] = u;
        rank[u]++;
    }
}

int minimumSpanningTree(vector<vector<int>> &edges, int n)
{
    sort(edges.begin(), edges.end(), compare);
    vector<int> parent(n);
    vector<int> rank(n);
    makeSet(parent, rank, n);
    int minwt = 0;

    for (int i = 0; i < edges.size(); i++) // make mst
    {
        int u = findParent(parent, edges[i][0]);
        int v = findParent(parent, edges[i][1]);
        int wt = edges[i][2];
        if (u != v) // when parents are not equal
        {
            unionSet(u, v, parent, rank);
            minwt += wt;
        }
    }
    return minwt;
}