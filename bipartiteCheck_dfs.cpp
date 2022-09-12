#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// dfs stack
class Solution
{
public:
    bool colorBfs(int i, stack<int> &s, vector<int> &color, vector<vector<int>> &graph)
    {

        s.push(i);
        color[i] = 0;
        while (!s.empty())
        {
            int node = s.top();
            s.pop();

            for (auto nbr : graph[node])
            {
                if (color[nbr] == -1)
                {
                    s.push(nbr);
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
        stack<int> s;

        for (int i = 0; i < n; i++)
        {
            if (color[i] == -1)
            {
                if (!colorBfs(i, s, color, graph))
                    return false;
            }
        }
        return true;
    }
};

// dfs recursive
class Solution
{
public:
    bool colorDfs(int node, vector<int> &color, vector<vector<int>> &graph)
    {

        for (auto nbr : graph[node])
        {
            if (color[nbr] == -1)
            {
                color[nbr] = 1 - color[node];
                if (!colorDfs(nbr, color, graph))
                    return false;
            }
            else if (color[node] == color[nbr])
                return false;
        }
        return true;
    }

public:
    bool isBipartite(vector<vector<int>> &graph)
    {

        int n = graph.size();
        vector<int> color(n, -1);

        for (int i = 0; i < n; i++)
        {
            if (color[i] == -1)
            {
                color[i] = 0;
                if (!colorDfs(i, color, graph))
                    return false;
            }
        }
        return true;
    }
};