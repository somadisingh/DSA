#include <unordered_map>
#include <queue>
#include <list>

using namespace std;

vector<int> shortestPath(vector<pair<int, int>> edges, int n, int m, int s, int t)
{
    // create adjacency list
    unordered_map<int, list<int>> adj;
    for (int i = 0; i < m; i++)
    {
        int u = edges[i].first;
        int v = edges[i].second;
        adj[u].push_back(v);
        adj[v].push_back(u); // undirected graph
    }

    // bfs
    unordered_map<int, int> parent;
    queue<int> q;
    unordered_map<int, bool> visited;
    visited[s] = true;
    parent[s] = -1;
    q.push(s);

    while (!q.empty())
    {
        int front = q.front();
        q.pop();
        for (auto neighbours : adj[front])
        {
            if (!visited[neighbours])
            {
                q.push(neighbours);
                visited[neighbours] = true;
                parent[neighbours] = front;
            }
        }
    }

    // find shortest path
    vector<int> ans;
    int currentNode = t;
    ans.push_back(t);

    while (currentNode != s)
    {
        currentNode = parent[currentNode];
        ans.push_back(currentNode);
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
