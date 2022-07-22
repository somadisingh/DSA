#include <bits/stdc++.h>
using namespace std;

void prepAdjlist(unordered_map<int, set<int>> &adjList, vector<pair<int, int>> &edges)
{
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i].first;
        int v = edges[i].second;

        adjList[u].insert(v);
        adjList[v].insert(u); // unidirected graph
    }
}

void bfs(unordered_map<int, set<int>> &adjList, unordered_map<int, bool> &visited, vector<int> &ans, int node)
{

    queue<int> q; // creating a queue
    q.push(node);
    visited[node] = 1; // inserting front node and marking true

    while (!q.empty())
    {
        // fetching the front node
        int frontNode = q.front();
        q.pop();

        // pushing into answer array
        ans.push_back(frontNode);

        // traversing its neighbours
        for (auto i : adjList[frontNode])
        {
            if (!visited[i])
            {
                q.push(i);
                visited[i] = 1;
            }
        }
    }
}

vector<int> BFS(int vertex, vector<pair<int, int>> edges)
{
    unordered_map<int, set<int>> adjList; // store node and its neighbours
    vector<int> ans;                      // store bfs traversal
    unordered_map<int, bool> visited;     // check if a node is visited or not to avoid infinite loop
    prepAdjlist(adjList, edges);          // prepares an adjacency list

    // traverse all components since graph disconnected
    for (int i = 0; i < vertex; i++)
    {
        if (!visited[i])
            bfs(adjList, visited, ans, i);
    }
    return ans;
}