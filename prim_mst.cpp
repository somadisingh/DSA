#include <bits/stdc++.h>
using namespace std;

#include <unordered_map>
#include <list>
#include <limits.h>

vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
{
    // make unordered map
    unordered_map<int, list<pair<int, int>>> adj;
    for (int i = 0; i < g.size(); i++)
    {
        int u = g[i].first.first;
        int v = g[i].first.second;
        int w = g[i].second;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    // initialize the mst, key & parent array
    vector<int> parent(n + 1);
    vector<int> key(n + 1);
    vector<bool> mst(n + 1);
    for (int i = 0; i <= n; i++)
    {
        key[i] = INT_MAX;
        parent[i] = -1;
        mst[i] = false;
    }

    // set source's key to 0
    key[1] = 0;
    // start making mst
    for (int i = 1; i <= n; i++)
    {
        int mini = INT_MAX;
        int u;
        for (int j = 1; j <= n; j++)
        {
            if (mst[j] == false && key[j] < mini)
            {
                u = j;
                mini = key[j];
            }
        }
        mst[u] = true; // node visited
        // check adj list
        for (auto neighbour : adj[u])
        {
            int v = neighbour.first;
            int w = neighbour.second;
            if (mst[v] == false && w < key[v])
            { // if the node has not been visited && adj's w < key val
                key[v] = w;
                parent[v] = u;
            }
        }
    }

    vector<pair<pair<int, int>, int>> ans;
    for (int i = 2; i <= n; i++)
    { // since source's parent = -1 & source = 1
        ans.push_back({{parent[i], i}, key[i]});
    }
    return ans;
}
