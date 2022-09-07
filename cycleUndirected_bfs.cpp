#include <iostream>
#include <queue>
#include <vector>
#include <list>
#include <map>

using namespace std;

bool checkCycle(int src, map<int, list<int>> &adj, vector<bool> &vis, vector<int> &par)
{
    // mark the current node as visited
    vis[src] = 1;
    queue<int> q;
    q.push(src);
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        for (auto nbr : adj[node])
        {
            if (!vis[nbr])
            {
                q.push(nbr);
                vis[nbr] = 1;
                par[nbr] = node;
            }
            else if (vis[nbr] && par[node] != nbr) // if the node is already visited and the parent of the current node is not the neighbour, this means that node has already been visited and is not the parent of the current node, hence there is a cycle
                return true;
        }
    }
    return false;
}

string cycleDetection(vector<vector<int>> &edges, int n, int m)
{
    // create adj list, parent, visited mapping
    map<int, list<int>> adj;
    vector<bool> vis(n + 1, 0);
    vector<int> par(n + 1);

    for (int i = 0; i < m; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // traverse all components since graph can be disconnected
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            bool cycle = checkCycle(i, adj, vis, par);
            if (cycle)
                return "Yes";
        }
    }
    return "No";
}
