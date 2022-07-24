#include <bits/stdc++.h>
using namespace std;

#include <unordered_map>
#include <list>

bool cycleCheck(int node, unordered_map<int, bool> &visited, unordered_map<int, bool> &dfsvisited, unordered_map<int, list<int>> &adj)
{
    visited[node] = true;
    dfsvisited[node] = true;

    for (auto neighbours : adj[node])
    {
        if (!visited[neighbours])
        {
            bool cyclepresent = cycleCheck(neighbours, visited, dfsvisited, adj);
            if (cyclepresent)
                return true;
        }
        else if (dfsvisited[neighbours])
            return true;
    }
    dfsvisited[node] = false; // backtracking
    return false;
}

int detectCycleInDirectedGraph(int n, vector<pair<int, int>> &edges)
{

    unordered_map<int, list<int>> adj;
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i].first;
        int v = edges[i].second;
        adj[u].push_back(v);
    }
    unordered_map<int, bool> visited;
    unordered_map<int, bool> dfsvisited;

    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            bool cycle = cycleCheck(i, visited, dfsvisited, adj);
            if (cycle)
                return true;
        }
    }
    return false;
}