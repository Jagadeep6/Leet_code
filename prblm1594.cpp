#include <bits/stdc++.h>
using namespace std;

int maxProductPath(vector<vector<int>> &grid)
{
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<int>>bumble(m, vector<int>(n, INT_MAX));
    vector<vector<int>>optimus(m, vector<int>(n, INT_MIN));
    bumble[0][0] = optimus[0][0] = grid[0][0];
    for(int i = 1; i < m; i++)
    {
        bumble[i][0] = grid[i][0]*bumble[i-1][0];
        optimus[i][0] = grid[i][0]*optimus[i-1][0];
    }
    for(int i = 1; i < n; i++)
    {
        bumble[0][i] = grid[0][i]*bumble[0][i-1];
        optimus[0][i] = grid[0][i]*optimus[0][i-1];
    }

    for(int i = 1; i < m; i++)
    {
        for(int j = 1; j < n; j++)
        {
            if(grid[i][j] < 0)
            {
                bumble[i][j] = max(optimus[i-1][j], optimus[i][j-1])*grid[i][j];
                optimus[i][j] = min(bumble[i-1][j], bumble[i][j-1])*grid[i][j];
            }
            else
            {
                bumble[i][j] = min(bumble[i-1][j], bumble[i][j-1])*grid[i][j];
                optimus[i][j] = max(optimus[i-1][j], optimus[i][j-1])*grid[i][j];
            }
        }
    }

    if(optimus[m-1][n-1] >= 0)
    {
        return optimus[m-1][n-1];
    }
    return -1;
}

int main()
{
}