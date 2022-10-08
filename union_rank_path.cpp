#include <vector>
#include <iostream>

using namespace std;

class Solution
{
public:
    bool findPath(int s, vector<int> adj[], vector<bool> &vis, int d)
    {
        vis[s] = 1;

        for (auto nbr : adj[s])
        {
            if (nbr == d)
                return true;
            if (!vis[nbr])
            {
                if (findPath(nbr, adj, vis, d))
                    return true;
            }
        }

        // vis[s] = 0;
        return false;
    }
    bool validPath(int n, vector<vector<int>> &edges, int source, int destination)
    {

        if (edges.size() == 0)
            return (source == destination);

        vector<int> adj[n];
        for (int i = 0; i < edges.size(); i++)
        {
            int u = edges[i][0], v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<bool> vis(n, 0);

        return findPath(source, adj, vis, destination);
    }
};

int main()
{
    int n = 3;
    vector<vector<int>> edges = {{0, 1}, {1, 2}, {0, 2}};
    int source = 0, destination = 2;
    Solution s;
    cout << s.validPath(n, edges, source, destination) << endl;
    return 0;
}