#include <bits/stdc++.h>
using namespace std;
void dfs(vector<vector<int>> &heights, vector<vector<bool>> &vis, int i, int j, int m, int n)
{
    vis[i][j] = true;
    if(i > 0 and heights[i-1][j] >= heights[i][j] and !vis[i-1][j])
    {
        dfs(heights, vis, i-1, j, m, n);
    }
    if(j > 0 and heights[i][j-1] >= heights[i][j] and !vis[i][j-1])
    {
        dfs(heights, vis, i, j-1, m, n);
    }
    if(i < m-1 and heights[i+1][j] >= heights[i][j] and !vis[i+1][j])
    {
        dfs(heights, vis, i+1, j, m, n);
    }
    if(j < n-1 and heights[i][j+1] >= heights[i][j] and !vis[i][j+1])
    {
        dfs(heights, vis, i, j+1, m, n);
    }
}

vector<vector<int>> pacificAtlantic(vector<vector<int>> &heights)
{
    int m = heights.size();
    int n = heights[0].size();

    vector<vector<bool>> pacific(m, vector<bool>(n));
    vector<vector<bool>> atlantic(m, vector<bool>(n));

    for(int i = 0; i < m; i++)
    {
        dfs(heights, pacific, i, 0, m, n);
        dfs(heights, atlantic, i, n-1, m, n);
    }
    for(int i = 0; i < n; i++)
    {
        dfs(heights, pacific, 0, i, m, n);
        dfs(heights, atlantic, m-1, i, m, n);
    }

    vector<vector<int>>res;
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(pacific[i][j] and atlantic[i][j])
            {
                res.push_back({i, j});
            }
        }
    }

    return res;
}