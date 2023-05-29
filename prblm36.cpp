#include <bits/stdc++.h>
using namespace std;

bool isValidSudoku(vector<vector<char>> &board)
{
    unordered_set<string> mp;
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (board[i][j] == '.')
            {
                continue;
            }
            else
            {
                string row = "r"+to_string(board[i][j])+to_string(j);
                string col = "c"+to_string(board[i][j])+to_string(j);
                int box = (i/3)*3 + j/3;
                string b = "b"+to_string(board[i][j])+to_string(box);
                if (mp.find(row) != mp.end() or mp.find(col) != mp.end() or mp.find(b) != mp.end())
                {
                    return false;
                }
                mp.insert(row);
                mp.insert(col);
                mp.insert(b);
            }
        }
    }

    return true;
}

int main()
{

}