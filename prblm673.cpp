#include <bits/stdc++.h>
using namespace std;

int findNumberOfLIS(vector<int> &nums)
{
    int n = nums.size();
    vector<int>dp(n, 1);
    vector<int> count(n, 1);

    int maxLen = 1;
    int res = 0;
    for(int i = n-2; i >=0; i--)
    {
        for(int j = i+1; j < n; j++)
        {
            if(nums[i] < nums[j])
            {
                if(dp[i] < dp[j]+1)
                {
                    dp[i] = dp[j]+1;
                    count[i] = count[j];
                }
                else if(dp[i] == dp[j]+1)
                {
                    count[i] += count[j];
                }
            }
        }
        maxLen = max(maxLen, dp[i]);
    }

    for(int i = 0; i < n; i++)
    {
        if(dp[i] == maxLen)
        {
            res += count[i];
        }
    }
    return res;
}

int main()
{
    vector<int> nums = {2,2,2,2,2};
    cout << findNumberOfLIS(nums) << endl;
    return 0;
}