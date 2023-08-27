#include <bits/stdc++.h>
using namespace std;

int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
{
    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();
    vector<vector<int>> path(m, vector<int> (n,0));
    
    for(int i = 0; i < m; i++)
    {
        if(obstacleGrid[i][0] != 1)
        {
            path[i][0] = 1;
        }
        else
        {
            break;
        }
    }
    for(int i = 0; i < n; i++)
    {
        if(obstacleGrid[0][i] != 1)
        {
            path[0][i] = 1;
        }
        else
        {
            break;
        }
    }
    
    if(m == 1 or n==1)
    {
        return path[m-1][n-1];
    }
    for(int i = 1; i < m; i++)
    {
        for(int j = 1; j < n; j++)
        {
            if(obstacleGrid[i][j] != 1)
            {
                path[i][j] = path[i-1][j] + path[i][j-1];
            }
        }
    }

    return path[m-1][n-1];
}

int main()
{
    vector<vector<int>>obstacleGrid = {{0,0,0},{0,1,0},{0,0,0}};
    cout << uniquePathsWithObstacles(obstacleGrid) << endl;
    return 0;
}