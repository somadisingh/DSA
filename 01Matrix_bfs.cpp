/*
Given an m x n binary matrix mat, return the distance of the nearest 0 for each cell.
The distance between two adjacent cells is 1.
*/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
    vector<vector<int>> updateMatrix(vector<vector<int>> &mat)
    {

        int m = mat.size();
        int n = mat[0].size();
        vector<vector<bool>> vis(m, vector<bool>(n, 0));
        vector<vector<int>> dist(m, vector<int>(n, 0));
        queue<pair<pair<int, int>, int>> q;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (mat[i][j] == 0)
                {
                    q.push({{i, j}, 0});
                    vis[i][j] = 1;
                }
            }
        }

        int rowVar[] = {-1, 0, +1, 0};
        int colVar[] = {0, +1, 0, -1};

        while (!q.empty())
        {
            int row = q.front().first.first;
            int col = q.front().first.second;
            dist[row][col] = q.front().second;
            q.pop();

            for (int i = 0; i < 4; i++)
            {
                int newRow = row + rowVar[i];
                int newCol = col + colVar[i];

                if (newRow >= 0 && newRow < m && newCol >= 0 && newCol < n && !vis[newRow][newCol])
                {
                    vis[newRow][newCol] = 1;
                    q.push({{newRow, newCol}, dist[row][col] + 1});
                }
            }
        }
        return dist;
    }
};