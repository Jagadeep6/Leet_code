#include <bits/stdc++.h>
using namespace std;

int valueAtCur(int cur, int n, vector<vector<int>> &board)
{
    int r = n-(cur-1)/n-1;  
    int c = (cur-1)%n;
    if(r%2==n%2)
    {
        return board[r][n-c-1];
    }
    return board[r][c];
}

int snakesAndLadders(vector<vector<int>> &board)
{
    int n = board.size();
    int moves = 0;
    vector<bool> vis(n*n +1, 0);
    queue<pair<int, int>>q;
    q.push({1, 0});
    vis[1] = 1;
    while(!q.empty())
    {
        int cur = q.front().first;
        int prev = q.front().second;
        q.pop();
        if(cur == n*n)
        {
            return moves;
        }
        for(int i = cur+1; i <= min(cur+6, n*n); i++)
        {
            if(vis[i])
            {
                continue;
            }
            vis[i] = true;
            int temp = valueAtCur(i, n, board);
            if(temp == -1)
            {
                q.push({i, moves+1});
            }
            else
            {
                if(valueAtCur(temp, n, board) == -1)
                {
                    vis[temp] = true;
                }
                q.push({temp, moves +1});
            }
        }
    }
    
    return -1;
}

int main()
{
    cout << 3*3 +1;
    return 0;
}