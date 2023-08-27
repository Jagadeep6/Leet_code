#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        int n = nums.size();
        int ans = 1;
        vector<int> dp(n, 1);
        for (int i = n - 2; i >= 0; i--)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (nums[i] < nums[j])
                {
                    dp[i] = max(dp[i], 1 + dp[j]);
                    ans = max(ans, dp[i]);
                }
            }
        }
        return ans;
    }
};

int lengthOfLIS(vector<int> &nums)
{
    int n = nums.size();
    vector<int> dp(n, 1);
    int ans = 1;
    for(int i = n-2; i>=0; i--)
    {
        for(int j = i+1; j < n; j++)
        {
            if(nums[i] < nums[j])
            {
                dp[i] = max(dp[i], 1+dp[j]);
                ans = max(ans, dp[i]);
            }
        }
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    cout << lengthOfLIS(nums) << endl;
    return 0;
}