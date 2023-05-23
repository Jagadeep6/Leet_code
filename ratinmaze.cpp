#include <bits/stdc++.h>
using namespace std;

bool isSafe(vector<vector<int>> &grid, int i, int j)
{
    int m = grid.size();
    int n = grid[0].size();
    if (i >= 0 and j >= 0 and i < m and j < n)
    {
        if (grid[i][j] == 1)
        {
            return true;
        }
    }
    return false;
}

void solve(vector<vector<int>> &grid, int m, int n, vector<string> &res, string &s, int row, int col)
{
    if (row == m - 1 and col == n - 1)
    {
        res.push_back(s);
        return;
    }

    if(isSafe(grid, row, col))
    {
        if(isSafe(grid, row+1, col))
        {
            s+= 'D';
            solve(grid, m, n, res, s, row+1, col);
            s.pop_back();
        }
        if(isSafe(grid, row, col+1))
        {
            s+='R';
            solve(grid, m, n, res, s, row, col+1);
            s.pop_back();
        }
    }
    return;
}
vector<string> findPaths(vector<vector<int>> &grid)
{
    vector<string> res;
    string temp = "";
    solve(grid, grid.size(), grid[0].size(), res, temp, 0, 0);
    return res;
}

int main()
{
    vector<vector<int>> m = {{1, 0, 0, 0}, {1, 1, 0, 1}, {1, 1, 0, 0}, {0, 1, 1, 1}};
    vector<string> res = findPaths(m);
    cout << res.size() << endl;
    cout << res[0] << ' ' << res[1] << endl;
    return 0;
}