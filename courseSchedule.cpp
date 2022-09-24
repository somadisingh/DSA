#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    bool checkCycle(int node, vector<int> adj[], vector<bool> &vis, vector<bool> &dfs)
    {
        vis[node] = 1;
        dfs[node] = 1;
        for (auto nbr : adj[node])
        {
            if (!vis[nbr])
            {
                if (checkCycle(nbr, adj, vis, dfs))
                    return true;
            }
            else if (dfs[nbr])
                return true;
        }
        dfs[node] = 0;
        return false;
    }

public:
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        int n = numCourses;
        int e = prerequisites.size();
        vector<int> adj[n];
        for (int i = 0; i < e; i++)
        {
            int u = prerequisites[i][0];
            int v = prerequisites[i][1];
            adj[u].push_back(v);
        }
        vector<bool> vis(n, 0);
        vector<bool> dfs(n, 0);

        for (int i = 0; i < n; i++)
        {
            if (!vis[i])
            {
                if (checkCycle(i, adj, vis, dfs))
                    return false;
            }
        }
        return true;
    }
};