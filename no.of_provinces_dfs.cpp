#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    void dfs(int city, vector<bool> &vis, vector<int> adj[])
    {
        vis[city] = 1;

        for (auto &it : adj[city])
        {
            if (!vis[it])
                dfs(it, vis, adj);
        }
    }

public:
    int findCircleNum(vector<vector<int>> &isConnected)
    {

        int n = isConnected.size();
        vector<int> adj[n];
        vector<bool> vis(n, 0);

        // prep adjacency list
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (isConnected[i][j] == 1)
                    adj[i].push_back(j), adj[j].push_back(i);
            }
        }

        // traverse over connected components
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            if (!vis[i])
                count++, dfs(i, vis, adj);
        }
        return count;
    }
};