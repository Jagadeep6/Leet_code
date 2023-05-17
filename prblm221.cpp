#include <bits/stdc++.h>
using namespace std;

int maximalSquare(vector<vector<char>> &matrix)
{
    int ans = 0;
    int m = matrix.size(), n = matrix[0].size();
    vector<vector<int>> dp(m, vector<int>(n, 0));
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(matrix[i][j] == '1')
            {
                dp[i][j] = 1;
                if(i-1>=0 and j-1>=0)
                {
                    dp[i][j]=min({dp[i][j-1], dp[i-1][j-1], dp[i-1][j]})+1;
                }
                ans = max(ans, dp[i][j]);
            }
            //cout << dp[i][j] << ' ';
        }
        //cout << endl;
    }
    return ans*ans; 
}

int main()
{
    vector<vector<char>> matrix = {{'1', '0', '1', '0', '0'}, {'1', '0', '1', '1', '1'},{'1', '1', '1', '1', '1'}, {'1', '0', '1', '1', '1'}};
    cout << maximalSquare(matrix) << endl;
    return 0;
}