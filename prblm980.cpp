#include <bits/stdc++.h>
using namespace std;

vector<int> dir = {0, -1, 0, 1, 0};

int solve(vector<vector<int>> &grid, pair<int, int> end, 
int noOfSpaces, int r, int c, int m, int n)
{
    if(r < 0 or  r >= m or c >= n or c < 0 or grid[r][c] == -1)
    {
        return 0;
    }
    if(r == end.first and c == end.second)
    {
        if(noOfSpaces == -1)
        {
            cout << "check" << endl;
            return 1;
        }
        else
        {
            return 0;
        }
    }
    grid[r][c] = -1;
    int sum = 0;
    for(int i = 0; i < 4; i++)
    {
        sum += solve(grid, end, noOfSpaces-1, r+dir[i], c+dir[i+1], m, n);
    }
    grid[r][c] = 0;
    return sum;
}

int uniquePathsIII(vector<vector<int>> &grid)
{
    int m = grid.size(), n = grid[0].size();
    int noOfSpaces  = 0;
    pair<int, int> start, end;
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            switch (grid[i][j])
            {
            case 1:
                start = {i, j};
                break;
            case 2:
                end = {i, j};
                break;
            case 0:
                noOfSpaces++;
                break;
            }
        }
    }
    int res = 0;
    res = solve(grid, end, noOfSpaces, start.first, start.second, m, n);
    return res;
}

int main()
{
    vector<vector<int>> grid = {{1,0,0,0},{0,0,0,0},{0,0,2,-1}};
    cout << uniquePathsIII(grid) << endl;
}