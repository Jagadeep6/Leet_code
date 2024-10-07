#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool exist(vector<vector<char>> &board, string word)
    {
        int m = board.size();
        int n = board[0].size();
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (board[i][j] == word[0])
                {
                    if (solve(board, word, 0, i, j, m, n))
                    {
                        return true;
                    }
                }
            }
        }

        return false;
    }

private:
    bool solve(vector<vector<char>> &board, string word, int index, int i, int j, int m, int n)
    {
        if (i < 0 or i >= m or j < 0 or j >= n or board[i][j] != word[index])
        {
            return false;
        }

        if (index == word.size() - 1)
            return true;
        board[i][j] = '#';

        if (solve(board, word, index + 1, i , j, m, n) or solve(board, word, index + 1, i, j + 1, m, n) or solve(board, word, index + 1, i - 1, j, m, n) or solve(board, word, index + 1, i, j - 1, m, n))
        {
            return true;
        }
        board[i][j] = word[index];
        return false;
    }
};