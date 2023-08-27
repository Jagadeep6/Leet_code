#include <bits/stdc++.h>
using namespace std;
//arthematicSubsequence
int TLE_longestSubsequence(vector<int> &arr, int difference)
{
    //Works but "TLE"
    int n = arr.size();
    vector<int>dp(n, 1);
    int res = 1;
    for(int i = 0; i < n; i++)
    {
        int prev = i;
        for(int j = i+1; j < n; j++)
        {   
            if(arr[prev]+difference == arr[j])
            {
                dp[j] = max(dp[i], 1+dp[prev]);
                prev = j;
            }
        }
        res = max(res, dp[i]);
        cout << dp[i] << ' ';
    }
    cout << endl;
    return res;
}

int longestSubsequence(vector<int> &arr, int difference)
{
    int n = arr.size();
    unordered_map<int, int> dp;
    int ans = 1;
    for(int i = 0; i < n; i++)
    {
        int cur = arr[i];
        if(dp.find(cur-difference) != dp.end())
        {
            dp[cur] = dp[cur-difference]+1;
        }
        else
        {
            dp[cur] = 1;
        }
        ans = max(ans, dp[cur]);
    }
    return ans;
}

int main()
{
    vector<int> nums = {1, 2, 3, 5, 4, 6, 8, 10};
    int diff = 2;
    cout << longestSubsequence(nums, diff) << endl;
    return 0;
}