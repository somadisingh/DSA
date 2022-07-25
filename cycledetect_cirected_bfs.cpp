#include <unordered_map>
#include <list>
#include <queue>

using namespace std;

int detectCycleInDirectedGraph(int n, vector<pair<int, int>> &edges)
{

    // create adjList
    unordered_map<int, list<int>> adj;
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i].first - 1;
        int v = edges[i].second - 1;
        adj[u].push_back(v);
    }

    // create indegree vector
    vector<int> indegree(n);
    for (auto i : adj)
    {
        for (auto j : i.second)
        {
            indegree[j]++;
        }
    }
    queue<int> q;
    // insert 0 degree nodes into q
    for (int i = 0; i < n; i++)
    {
        if (indegree[i] == 0)
            q.push(i);
    }

    int count = 0;
    // do bfs
    while (!q.empty())
    {
        int front = q.front();
        q.pop();
        count++;
        for (auto neighbours : adj[front])
        {
            indegree[neighbours]--;
            if (indegree[neighbours] == 0)
                q.push(neighbours);
        }
    }
    if (count == n)
        return false;
    else
        return true;
}