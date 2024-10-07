#include <bits/stdc++.h>
using namespace std;

map<pair<int, int>, bool> dp;

bool dfs(string s1, string s2, string s3, int i, int j)
{
    if(i == s1.size() and j == s2.size())
    {
        return true;
    }
    if(dp.find({i, j}) != dp.end())
    {
        return dp[{i, j}];
    } 
    if(i < s1.size() and s1[i] == s3[i+j] and dfs(s1, s2, s3, i+1, j))
    {
        return true;
    }
    if(j < s2.size() and s2[j] == s3[i+j] and dfs(s1, s2, s3, i, j+1))
    {
        return true;
    }

    dp[{i, j}] = false;
    return dp[{i, j}];
}

bool isInterleave(string s1, string s2, string s3)
{
    if (s1.size() + s2.size() != s3.size())
    {
        return false;
    }
    
    return dfs(s1, s2, s3, 0, 0);
}

int main()
{
}