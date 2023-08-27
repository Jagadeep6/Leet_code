#include <bits/stdc++.h>
using namespace std;

    int asciiSum(string s)
    {
        int res = 0;
        for(int i = 0; i < s.size(); i++)
        {
            res += s[i];
        }
        return res;
    }

    int minimumDeleteSum(string s1, string s2)
    {
        int m = s1.size();
        int n = s2.size();
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        for(int i = 1; i <= m; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                if(s1[i-1] == s2[j-1])
                {
                    dp[i][j] = s1[i-1] + dp[i-1][j-1];
                }
                else
                {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }

        int res = asciiSum(s1)+asciiSum(s2) - (2*dp[m][n]);
        return res;
    }

int main()
{
    cout << minimumDeleteSum("delete", "leet") << endl;
    cout << minimumDeleteSum("sea", "eat") << endl;
    return 0;
}