#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int>> neighbours = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}, {1, 1}, {-1, -1}, {1, -1}, {-1, 1}};
int shortestPathBinaryMatrix(vector<vector<int>> &grid)
{
    int m = grid.size();
    int n = grid[0].size();

    queue<pair<pair<int, int>, int>> q;
    q.push({{0, 0}, 1});
    if (grid[0][0] == 1)
    {
        return -1;
    }
    vector<vector<bool>> vis(m, vector<bool>(n, 0));
    if (grid[0][0] == 0 and grid.size() == 1 and grid[0].size() == 1)
    {
        return 1;
    }

    while (!q.empty())
    {
        pair<int, int> top = q.front().first;
        int r = top.first;
        int c = top.second;
        int len = q.front().second;

        q.pop();
        for (auto i : neighbours)
        {
            int n_row = r + i.first;
            int n_col = c + i.second;

            if (n_row >= 0 and n_row < m and n_col >= 0 and n_col < n and grid[n_row][n_col] == 0 and vis[n_row][n_col] == false)
            {
                q.push({{n_row, n_col}, len + 1});
                vis[n_row][n_col] == true;
                if (n_row == m - 1 and n_col == n - 1)
                {
                    return len + 1;
                }
            }
        }
    }

    return -1;
}

int main()
{
}