#include <bits/stdc++.h>
using namespace std;

int orangesRotting(vector<vector<int>> &grid)
{
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<int>> temp = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    queue<pair<int, int>> q;
    int fresh = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (grid[i][j] == 2)
            {
                q.push({i, j});
            }
            else if (grid[i][j] == 1)
            {
                fresh++;
            }
        }
    }
    int time = -1;
    q.push({-1, -1});
    while (!q.empty())
    {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();
        if (r == -1)
        {
            time++;
            if (!q.empty())
            {
                q.push({-1, -1});
            }
        }
        else
        {
            for (int i = 0; i < temp.size(); i++)
            {
                int cur_r = r + temp[i][0];
                int cur_c = c + temp[i][1];
                if(cur_r >= 0 and cur_r < m and cur_c >= 0 and cur_c < n)
                {
                    if(grid[cur_r][cur_c] == 1)
                    {
                        grid[cur_r][cur_c] = 2;
                        q.push({cur_r, cur_c});
                        fresh--;
                    }
                }
            }
        }
    }
    if(fresh == 0)
    {
        return time;
    }
    return -1;
}

int main()
{
    vector<vector<int>> grid = {{2, 1, 1}, {1, 1, 0}, {0, 1, 1}};
    cout << orangesRotting(grid) << endl;
    return 0;
}