#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution
{
public:
    void rotOranges(int row, int col, queue<pair<int, int>> &q, vector<vector<int>> &grid)
    {

        if (row - 1 >= 0)
        {
            if (grid[row - 1][col] == 1)
            {
                q.push({row - 1, col});
                grid[row - 1][col] = 2;
            }
        }
        if (row + 1 < grid.size())
        {
            if (grid[row + 1][col] == 1)
            {
                q.push({row + 1, col});
                grid[row + 1][col] = 2;
            }
        }
        if (col - 1 >= 0)
        {
            if (grid[row][col - 1] == 1)
            {
                q.push({row, col - 1});
                grid[row][col - 1] = 2;
            }
        }
        if (col + 1 < grid[0].size())
        {
            if (grid[row][col + 1] == 1)
            {
                q.push({row, col + 1});
                grid[row][col + 1] = 2;
            }
        }
    }

public:
    int orangesRotting(vector<vector<int>> &grid)
    {

        // create a queue of coordinates
        queue<pair<int, int>> q;

        // insert all coordinates having rotten oranges
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (grid[i][j] == 2)
                {
                    q.push({i, j});
                }
            }
        }

        int time = 0;
        // BFS traversal
        while (!q.empty())
        {
            int size = q.size();
            // traverse on a level
            for (int i = 0; i < size; i++)
            {
                int row = q.front().first;
                int col = q.front().second;
                q.pop();
                rotOranges(row, col, q, grid); // rot all neighbouring oranges
            }
            time++; // when a level has been traversed increment time
        }

        // check if there are any fresh oranges. if yes return -1
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (grid[i][j] == 1)
                    return -1;
            }
        }

        if (time == 0)
            return 0; // if none of the oranges were rotten return 0
        return time - 1;
    }
};