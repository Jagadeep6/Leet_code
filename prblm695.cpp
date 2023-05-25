#include <bits/stdc++.h>
using namespace std;

int maxAreaOfIsland(vector<vector<int>> &grid)
{
    int m = grid.size();
    int n = grid[0].size();
    int res = 0;
    vector<vector<bool>> vis(m, vector<bool>(n, 0));
    vector<int> dx = {1, 0, -1, 0};
    vector<int> dy = {0, 1, 0, -1};
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (grid[i][j] == 1 and vis[i][j] == 0)
            {
                int temp = 0;
                queue<pair<int, int>> q;
                q.push({i, j});
                vis[i][j] = 1;
                while (!q.empty())
                {
                    int r = q.front().first;
                    int c = q.front().second;
                    q.pop();
                    temp++;
                    for (int k = 0; k < 4; k++)
                    {
                        int cur_r = r + dx[k];
                        int cur_c = c + dy[k];
                        if (cur_r >= 0 and cur_r < m and cur_c >= 0 and cur_c < n and
                            grid[cur_r][cur_c] == 1 and vis[cur_r][cur_c] == 0)
                        {
                            q.push({cur_r, cur_c});
                            vis[cur_r][cur_c] = 1;
                        }
                    }
                }
                res = max(temp, res);
            }
        }
    }
    return res;
}

int main()
{
}