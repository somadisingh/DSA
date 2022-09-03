#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    void dfs(int i, int j, int color, vector<vector<int>> &image, int start)
    {
        // out of bounds
        if (i > image.size() - 1 || i < 0 || j > image[0].size() - 1 || j < 0)
            return;

        // already colored or not some other color != image[sr][sc]
        if (image[i][j] != start || image[i][j] == color)
            return;

        image[i][j] = color;

        dfs(i - 1, j, color, image, start);
        dfs(i + 1, j, color, image, start);
        dfs(i, j - 1, color, image, start);
        dfs(i, j + 1, color, image, start);
    }

public:
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
    {

        int start = image[sr][sc];
        dfs(sr, sc, color, image, start);
        return image;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> image = {{1, 1, 1}, {1, 1, 0}, {1, 0, 1}};
    int sr = 1, sc = 1, color = 2;
    vector<vector<int>> ans = s.floodFill(image, sr, sc, color);
    for (auto &i : ans)
    {
        for (auto &j : i)
            cout << j << " ";
        cout << endl;
    }
    return 0;
}