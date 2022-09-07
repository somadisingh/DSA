#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// DFS

class Solution
{
public:
    void forbidEnclave(int i, int j, int m, int n, vector<vector<int>> &grid, vector<vector<bool>> &vis)
    {

        if (i < 0 || j < 0 || i >= m || j >= n || vis[i][j] || grid[i][j] == 0)
            return;

        vis[i][j] = true;

        forbidEnclave(i - 1, j, m, n, grid, vis);
        forbidEnclave(i + 1, j, m, n, grid, vis);
        forbidEnclave(i, j - 1, m, n, grid, vis);
        forbidEnclave(i, j + 1, m, n, grid, vis);

        return;
    }

public:
    int numEnclaves(vector<vector<int>> &grid)
    {

        int count = 0;
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<bool>> vis(m, vector<bool>(n, 0));

        // traversing first and last row
        for (int j = 0; j < n; j++)
        {
            if (!vis[0][j] && grid[0][j] == 1)
                forbidEnclave(0, j, m, n, grid, vis);
            if (!vis[m - 1][j] && grid[m - 1][j] == 1)
                forbidEnclave(m - 1, j, m, n, grid, vis);
        }

        // traversing first and last column
        for (int i = 0; i < m; i++)
        {
            if (!vis[i][0] && grid[i][0] == 1)
                forbidEnclave(i, 0, m, n, grid, vis);
            if (!vis[i][n - 1] && grid[i][n - 1] == 1)
                forbidEnclave(i, n - 1, m, n, grid, vis);
        }

        // counting the number of enclaves
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (!vis[i][j] && grid[i][j] == 1)
                    count++;
            }
        }
        return count;
    }
};

// BFS

int numEnclaves(vector<vector<int>> &grid)
{

    int count = 0;
    int m = grid.size();
    int n = grid[0].size();

    vector<vector<bool>> vis(m, vector<bool>(n, 0));
    queue<pair<int, int>> q;

    // traversing first and last row
    for (int j = 0; j < n; j++)
    {
        if (!vis[0][j] && grid[0][j] == 1)
            vis[0][j] = 1, q.push({0, j});
        if (!vis[m - 1][j] && grid[m - 1][j] == 1)
            vis[m - 1][j] = 1, q.push({m - 1, j});
    }

    // traversing first and last column
    for (int i = 0; i < m; i++)
    {
        if (!vis[i][0] && grid[i][0] == 1)
            vis[i][0] = 1, q.push({i, 0});
        if (!vis[i][n - 1] && grid[i][n - 1] == 1)
            vis[i][n - 1] = 1, q.push({i, n - 1});
    }

    int varRow[] = {-1, 0, +1, 0};
    int varCol[] = {0, +1, 0, -1};

    while (!q.empty())
    {
        int row = q.front().first;
        int col = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int newRow = row + varRow[i];
            int newCol = col + varCol[i];
            if (newRow >= 0 && newCol >= 0 && newRow < m && newCol < n && !vis[newRow][newCol] && grid[newRow][newCol] == 1)
            {
                vis[newRow][newCol] = 1;
                q.push({newRow, newCol});
            }
        }
    }

    // counting the number of enclaves
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (!vis[i][j] && grid[i][j] == 1)
                count++;
        }
    }
    return count;
}