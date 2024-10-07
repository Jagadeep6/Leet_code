#include <bits/stdc++.h>
using namespace std;

int minFallingPathSum(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    vector<vector<int>>dp(n, vector<int>(n, 0));
    int res = INT_MAX;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(i==0)
            {
                dp[i] = matrix[i];                
            }
            else
            {
                int shortestFall =INT_MAX;
                if(j-1 >= 0)
                {
                    shortestFall = min(dp[i-1][j-1], shortestFall);
                }
                shortestFall = min(dp[i-1][j], shortestFall);
                if(j+1 < n)
                {
                    shortestFall = min(dp[i-1][j+1], shortestFall);
                }
                dp[i][j] = matrix[i][j]+shortestFall;
            }

            if(i == n-1)
            {
                res = min(res, dp[i][j]);
            }
        }
    }
    return res;
}

int main()
{
    vector<vector<int>>matrix = {{2,1,3},{6,5,4},{7,8,9}};
    cout << minFallingPathSum(matrix) << endl;
    return  0;
}