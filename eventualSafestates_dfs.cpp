#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    bool dfs(int node, vector<bool> &vis, vector<bool> &path, vector<bool> &safe, vector<vector<int>> &graph)
    {
        vis[node] = 1;
        path[node] = 1;
        safe[node] = 0;

        for (auto nbr : graph[node])
        {
            if (!vis[nbr])
            {
                if (dfs(nbr, vis, path, safe, graph))
                {                  // if cycle present
                    safe[nbr] = 0; // mark nbr unsafe
                    return true;
                }
            }
            else if (path[nbr])
            {                  // if cycle present
                safe[nbr] = 0; // mark nbr unsafe
                return true;
            }
        }

        safe[node] = 1; // the above for loop is over, meaning no cycle present hence node is safe
        path[node] = 0;
        return false;
    }

public:
    vector<int> eventualSafeNodes(vector<vector<int>> &graph)
    {

        int n = graph.size();
        vector<bool> vis(n, 0), path(n, 0), safe(n, 0); // safe array to store the safe nodes
        for (int i = 0; i < graph.size(); i++)
        {
            if (!vis[i])
                dfs(i, vis, path, safe, graph);
        }
        vector<int> ans;
        for (int i = 0; i < safe.size(); i++)
        {
            if (safe[i])
                ans.push_back(i);
        }
        return ans;
    }
};