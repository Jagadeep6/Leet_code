#include <bits/stdc++.h>
using namespace std;

int longestCommonSubsequence(string text1, string text2)
{
    int m = text1.size();
    int n = text2.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    for (int i = 0; i < m + 1; i++)
    {
        for (int j = 0; j < n + 1; j++)
        {
            if (i == 0 or j == 0)
            {
                dp[i][j] = 0;
            }
            else if (text1[i - 1] == text2[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[m][n];
}

int longestPalindromeSubseq(string s)
{
    string sf = s;
    reverse(sf.begin(), sf.end());
    return longestCommonSubsequence(s,sf);
}

int main()
{
    string s = "abcdcbab";
    cout << longestPalindromeSubseq(s);
    return 0;
}