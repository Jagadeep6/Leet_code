#include <bits/stdc++.h>
using namespace std;

int combinationSum4(vector<int> &nums, int target)
{
    sort(nums.begin(), nums.end());
    vector<int> dp(target+1, 0);
    dp[0]=1;
    for(int i = 1; i <= target; i++)
    {
        for(int j = 0; j < nums.size(); j++)
        {
            if(i-nums[j]>=0)
            {
                dp[i]+=dp[i-nums[j]];
            }
        }
    }
    return dp[target];
}

int main()
{
    int n = 3, target = 3;
    vector<int> nums = {1, 2, 3};
    cout << combinationSum4(nums, target);
    return 0;
}