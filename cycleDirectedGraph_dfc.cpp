#include <iostream>
#include <vector>

using namespace std;

bool dfs(int node, vector<int> adj[], vector<bool> &vis, vector<bool> &path)
{
    vis[node] = 1;
    path[node] = 1;

    for (auto nbr : adj[node])
    {
        if (!vis[nbr])
        {
            if (dfs(nbr, adj, vis, path))
                return true;
        }
        else if (path[nbr])
            return true;
    }
    path[node] = 0;
    return false;
}

int detectCycleInDirectedGraph(int n, vector<pair<int, int>> &edges)
{
    vector<bool> vis(n + 1, 0), path(n + 1, 0);
    vector<int> adj[n + 1];
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i].first;
        int v = edges[i].second;
        adj[u].push_back(v);
    }
    for (int i = 0; i <= n; i++)
    {
        if (!vis[i])
        {
            if (dfs(i, adj, vis, path))
                return true;
        }
    }
    return false;
}