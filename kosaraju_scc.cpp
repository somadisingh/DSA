#include <bits/stdc++.h>
using namespace std;

void dfs(int node, unordered_map<int, bool> &vis, stack<int> &s, unordered_map<int, list<int>> &adj)
{
    vis[node] = true;
    for (auto nbr : adj[node])
    {
        if (!vis[nbr])
            dfs(nbr, vis, s, adj);
    }
    s.push(node);
}

void redfs(int node, unordered_map<int, bool> &vis, unordered_map<int, list<int>> &transpose)
{
    vis[node] = true;
    for (auto nbr : transpose[node])
    {
        if (!vis[nbr])
        {
            redfs(nbr, vis, transpose);
        }
    }
}

int stronglyConnectedComponents(int v, vector<vector<int>> &edges)
{
    // create adj list
    unordered_map<int, list<int>> adj;
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v);
    }

    // top sort
    stack<int> s;
    unordered_map<int, bool> vis;
    for (int i = 0; i < v; i++)
    {
        if (!vis[i])
            dfs(i, vis, s, adj);
    }

    // transpose graph
    unordered_map<int, list<int>> transpose;
    for (int i = 0; i < v; i++)
    {
        vis[i] = false; // since visited array will be used again in second dfs call
        for (auto nbr : adj[i])
        {
            transpose[nbr].push_back(i);
        }
    }
    // dfs call using stack order
    int count = 0;
    while (!s.empty())
    {
        int top = s.top();
        s.pop();
        if (!vis[top])
        {
            count++;
            redfs(top, vis, transpose);
        }
    }
    return count;
}
