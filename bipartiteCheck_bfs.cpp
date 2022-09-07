#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution
{
public:
    bool colorBfs(int i, queue<int> &q, vector<int> &color, vector<vector<int>> &graph)
    {

        q.push(i);
        color[i] = 0;
        while (!q.empty())
        {
            int node = q.front();
            q.pop();

            for (auto nbr : graph[node])
            {
                if (color[nbr] == -1)
                {
                    q.push(nbr);
                    color[nbr] = 1 - color[node];
                }
                else if (color[node] == color[nbr])
                    return false;
            }
        }
        return true;
    }

public:
    bool isBipartite(vector<vector<int>> &graph)
    {

        int n = graph.size();
        vector<int> color(n, -1);
        queue<int> q;

        for (int i = 0; i < n; i++)
        {
            if (color[i] == -1)
            {
                if (!colorBfs(i, q, color, graph))
                    return false;
            }
        }
        return true;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> graph = {{1, 3}, {0, 2}, {1, 3}, {0, 2}};
    cout << s.isBipartite(graph) << endl;
    return 0;
}