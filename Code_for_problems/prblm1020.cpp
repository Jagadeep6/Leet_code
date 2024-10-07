#include <bits/stdc++.h>
using namespace std;
vector<int> dir = {0, 1, 0, -1, 0};

void bfs(vector<vector<int>> &grid, int i, int j, int m, int n)
{
    cout << i << ' ' << j << endl;
    queue<pair<int, int>> q;
    if(grid[i][j] == 1)
    {
        q.push({i, j});
        grid[i][j] = 0;
    }
    while(!q.empty())
    {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++)
        {
            int nr = r + dir[i];
            int nc = c + dir[i+1];
            if(nr < 0 or nr >= m or nc < 0 or nc >= n or grid[nr][nc] == 0)
            {
                continue;
            }
            grid[nr][nc] = 0;
            q.push({nr, nc});
        }
    }

    return;
}

int numEnclaves(vector<vector<int>>& grid)
{
    int m = grid.size();
    int n = grid[0].size();
    queue<pair<int, int>> q;
    for(int i = 0; i < m; i++)
    {
        if(grid[i][0] == 1)
        {
            q.push({i, 0});
            grid[i][0] = 0;
        }
        if(grid[i][n-1] == 1)
        {
            q.push({i, n-1});
            grid[i][n-1] = 0;
        }
    }

    for(int i = 0; i < n; i++)
    {
        if(grid[0][i] == 1)
        {
            q.push({0, i});
            grid[0][i] = 0;
        }
        if(grid[m-1][i] == 1)
        {
            q.push({m-1, i});
            grid[m-1][i] = 0;
        }
    }
    while(!q.empty())
    {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++)
        {
            int nr = r + dir[i];
            int nc = c + dir[i+1];
            if(nr < 0 or nr >= m or nc < 0 or nc >= n or grid[nr][nc] == 0)
            {
                continue;
            }
            grid[nr][nc] = 0;
            q.push({nr, nc});
        }
    }

    int res = 0;
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(grid[i][j] == 1)
            {
                res++;
            }
        }
    }

    return res;
}

int main()
{
    vector<vector<int>> grid = {{0,0,0,0},{1,0,1,0},{0,1,1,0},{0,0,0,0}};
    cout << numEnclaves(grid) << endl;
}