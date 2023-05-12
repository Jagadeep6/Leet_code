#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> generate(int n)
{
    vector<vector<int>> dp(n);
    for(int i = 0; i < n; i++)
    {
        dp[i].resize(i+1, 1);
        for(int j = 1; j < i; j++)
        {
            dp[i][j] = dp[i-1][j-1]+dp[i-1][j];
        }
    }
    return dp;
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> dp = generate(n);
    for(int i = 0; i < dp.size(); i++)
    {
        for(int j = 0; j < dp[i].size(); j++)
        {
            cout << dp[i][j] << ' ';
        }
        cout << endl;
    }
    return 0;
}