#include <bits/stdc++.h>
using namespace std;
    bool is_safe(vector<string> board, int n, int i, int j)
    {
        int cur_row = i;
        int cur_col = j;
        while(cur_row >= 0 and cur_row >=0)
        {
            cur_row--;
            cur_col--;
            if(board[cur_row][cur_col] == 'Q')
            {
                return false;
            }
        }
        cur_row = i;
        cur_col = j;
        while(cur_row >= 0 and cur_col < n)
        {
            cur_row--;
            cur_col++;
            if(board[cur_row][cur_col] == 'Q')
            {
                return false;
            }
        }
        cur_row = i;
        cur_col = j;
        while(cur_row >= 0)
        {
            cur_row--;
            if(board[cur_row][cur_col] == 'Q')
            {
                return false;
            }
        }

        return true;
    }
    
    void solve(vector<string> &board, vector<vector<string>> &ans, int n, int j)
    {
        if(j == n)
        {
            ans.push_back(board);
            //return;
        }
        for(int i = 0; i < n; i++)
        {
            if(is_safe(board, n, i, j))
            {
                board[i][j] = 'Q';
                solve(board, ans, n, j+1);
                board[i][j] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n)
    {
        vector<string> board(n, "");
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                board[i].push_back('.');
            }
        }
        vector<vector<string>> sol;
        solve(board, sol, n, 0);
        return sol;
    }

int main()
{
    int n = 4;
    vector<vector<string>> sol = solveNQueens(4);
    for(int i = 0; i < sol.size(); i++)
    {
        for(int j = 0; j < n; j++)
        {
            cout << sol[i][j] << endl;
        }
    }
    return 0;
}