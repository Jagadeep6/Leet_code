#include <bits/stdc++.h>
using namespace std;

bool checkPalindrome(string s)
{
    int i = 0, j = s.size()-1;
    while(i < j)
    {
        if(s[i] == s[j])
        {
            i++;
            j--;
        } 
        else
        {
            return false;
        }
    }
    return true;
}

int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size();
    int n = text2.size();
    vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
    for(int i = 0; i < m+1; i++)
    {
        for(int j = 0; j < n+1; j++)
        {
            if(i == 0 or j == 0)
            {
                dp[i][j] = 0;
            }
            else if(text1[i-1]==text2[j-1])
            {
                dp[i][j] = 1+dp[i-1][j-1];
            }
            else
            {
                dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    return dp[m][n];
}

int minInsertions(string s)
{
    int n = s.size();
    if(checkPalindrome(s))
    {
        return 0;
    }
    string sr = s;
    reverse(sr.begin(), sr.end());
    int m = longestCommonSubsequence(s, sr);
    return m-n;
}

int main()
{
}