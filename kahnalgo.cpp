#include <bits/stdc++.h>
using namespace std;

#include <unordered_map>
#include <queue>
#include <list>

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)
{
    // prep adj list
    unordered_map<int, list<int>> adj;
    for (int i = 0; i < e; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v);
    }
    // find all indegrees
    vector<int> indegree(v);
    for (auto i : adj)
    {
        for (auto j : i.second)
        {
            indegree[j]++;
        }
    }

    // insert nodes with indegree 0
    queue<int> q;
    for (int i = 0; i < v; i++)
    {
        if (indegree[i] == 0)
            q.push(i);
    }

    // bfs
    vector<int> ans;
    while (!q.empty())
    {
        int front = q.front();
        q.pop();
        ans.push_back(front);

        for (auto neighbours : adj[front])
        {
            indegree[neighbours]--;
            if (indegree[neighbours] == 0)
                q.push(neighbours);
        }
    }
    return ans;
}