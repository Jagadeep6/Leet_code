#include <bits/stdc++.h>
using namespace std;

int numDistinct(string s, string t)
{
    int m = s.size();
    int n = t.size();
    // vector<vector<int>> dp(m+1,  vector<int>(n+1, 0));
    vector<double> oneDP(n + 1, 0);
    oneDP[0] = 1;
    for (int i = 1; i <= m; i++)
    {
        for (int j = n; j >= 1; j--)
        {
            if (s[i - 1] == t[j - 1])
            {
                oneDP[j] +=  oneDP[j-1];
            }
        
            cout << oneDP[j] << ' ';
        }
        cout << endl;
    }
    return (int)oneDP[n];

    // for(int i = 0; i <= m; i++)
    // {
    //     dp[i][0] = 1;
    // }
    // for(int i = 1; i <=m; i++)
    // {
    //     for(int j = 1; j <= n; j++)
    //     {
    //         if(s[i-1] == t[j-1])
    //         {
    //             dp[i][j] = dp[i-1][j]+dp[i-1][j-1];
    //         }
    //         else
    //         {
    //             dp[i][j] = dp[i-1][j];
    //         }
    //     }
    // }

    // return dp[m][n];
}

int main()
{
    cout << numDistinct("rabbbit", "rabbit") << endl;
    cout << numDistinct("babgbag", "bag") << endl;
    return 0;
}