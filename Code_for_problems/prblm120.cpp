#include <bits/stdc++.h>
using namespace std;

int minimumTotal(vector<vector<int>> &triangle)
{
    int res = INT_MAX;
    int n = triangle.size();
    vector<vector<int>> dp(n);
    dp[0].push_back(triangle[0][0]);
    for(int i = 1; i < n; i++)
    {
        for(int j = 0; j <= i; j++)
        {
            if(j == 0 or j == i)
            {
                if(j == 0)
                {
                    dp[i].push_back(dp[i-1][j] + triangle[i][j]); 
                }
                else
                {
                    dp[i].push_back(dp[i-1][j-1] + triangle[i][j]);
                }
            }
            else
            {
                int next_step = min(dp[i-1][j], dp[i-1][j-1]) + triangle[i][j];
                dp[i].push_back(next_step);
            }
            cout << dp[i][j] << ' ';
        }
        cout << endl;
    }
    for(int i = 0; i < n; i++)
    {
        res = min(dp[n-1][i], res);
    }

    return res;
}

int main()
{
    vector<vector<int>>triangle = {{2},{3,4},{6,5,7},{4,1,8,3}};
    cout << minimumTotal(triangle) << endl;
    return 0;
}