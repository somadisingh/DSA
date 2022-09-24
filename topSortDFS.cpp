#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void dfs(int node, vector<int> adj[], vector<bool> &vis, stack<int> &s)
{                              // topological sort using dfs
    vis[node] = 1;             // mark node as visited
    for (auto nbr : adj[node]) // traverse the node's neighbours
    {
        if (!vis[nbr])             // if neighbour is not visited
            dfs(nbr, adj, vis, s); // call dfs on neighbour
    }
    s.push(node); // push the node in stack after all its neighbours are visited
}

vector<int> topologicalSort(vector<vector<int>> &graph, int edges, int nodes)
{
    vector<int> adj[nodes]; // array of vectors: adjacency list
    for (int i = 0; i < edges; i++)
    {
        int u = graph[i][0];
        int v = graph[i][1];
        adj[u].push_back(v);
    }
    vector<bool> vis(nodes, 0);     // visited array
    stack<int> s;                   // stack to store topological sort
    for (int i = 0; i < nodes; i++) // for disconnected graph
    {
        if (!vis[i])
            dfs(i, adj, vis, s);
    }
    vector<int> ans(nodes); // vector to store topological sort
    for (int i = 0; i < nodes; i++)
    {
        ans[i] = s.top();
        s.pop();
    }
    return ans;
}

int main()
{
    int nodes = 6;
    int edges = 6;
    vector<vector<int>> graph = {{0, 2}, {1, 2}, {1, 4}, {2, 3}, {2, 5}, {3, 5}};
    vector<int> ans = topologicalSort(graph, edges, nodes);
    for (auto x : ans)
        cout << x << " ";
    return 0;
}