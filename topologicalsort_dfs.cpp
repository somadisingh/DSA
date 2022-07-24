#include <bits/stdc++.h>
using namespace std;

#include <unordered_map>
#include <list>
#include <stack>

void topSort(int node, vector<bool> &visited, stack<int> &s, unordered_map<int, list<int>> &adj)
{
    visited[node] = true;

    for (auto neighbours : adj[node])
    {
        if (!visited[neighbours])
        {
            topSort(neighbours, visited, s, adj);
        }
    }
    s.push(node);
}

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)
{

    // prepare adjacency list
    unordered_map<int, list<int>> adj;
    for (int i = 0; i < e; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v);
    }

    // traverse all nodes and call topsort function
    vector<bool> visited(v);
    stack<int> s;
    for (int i = 0; i < v; i++)
    {
        if (!visited[i])
        {
            topSort(i, visited, s, adj);
        }
    }

    vector<int> ans;
    while (!s.empty())
    {
        ans.push_back(s.top());
        s.pop();
    }
    return ans;
}