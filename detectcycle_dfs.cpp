#include <bits/stdc++.h>
using namespace std;

#include <unordered_map>
#include <list>

bool cycleCheck(int node, int parent, unordered_map<int, bool> &visited, unordered_map<int, list<int>> &adjList)
{
    visited[node] = true;
    for (auto neighbour : adjList[node])
    {
        if (!visited[neighbour])
        {
            bool cycle = cycleCheck(neighbour, node, visited, adjList);
            if (cycle)
                return true;
        }
        else if (neighbour != parent)
            return true;
    }
    return false;
}

string cycleDetection(vector<vector<int>> &edges, int n, int m)
{
    unordered_map<int, list<int>> adjList;
    for (int i = 0; i < m; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    unordered_map<int, bool> visited;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            bool ans = cycleCheck(i, -1, visited, adjList);
            if (ans == 1)
            {
                return "Yes";
            }
        }
    }
    return "No";
}
