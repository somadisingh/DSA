#include <bits/stdc++.h>
using namespace std;

#include <unordered_map>
#include <queue>
#include <list>

bool cycleCheck(int src, unordered_map<int, bool> &visited, unordered_map<int, list<int>> &adjList)
{
    unordered_map<int, int> parent;
    parent[src] = -1; // starting node has no parent
    visited[src] = 1;
    queue<int> q;
    q.push(src);

    while (!q.empty())
    {
        int front = q.front();
        q.pop();
        for (auto neighbour : adjList[front])
        {
            if (visited[neighbour] == 1 && neighbour != parent[front])
            {
                return 1;
            }
            else if (!visited[neighbour])
            {
                q.push(neighbour);
                visited[neighbour] = true;
                parent[neighbour] = front;
            }
        }
    }
    return 0;
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
            bool ans = cycleCheck(i, visited, adjList);
            if (ans == 1)
            {
                return "Yes";
            }
        }
    }
    return "No";
}
