#include <bits/stdc++.h>
using namespace std;

int frogJump(int n, vector<int> &heights)
{
    vector<int> dp(n, INT_MAX);
    dp[0]= 0;
    for(int i = 0; i < n; i++)
    {
        if(i+1 < n)
        {
            dp[i+1] = min(dp[i+1], abs(heights[i+1]-heights[i]))+dp[i];
        }
        if(i+2 < n)
        {
            dp[i+2] = min(dp[i+2], abs(heights[i+2]-heights[i]))+dp[i];
        }
    }
    for(int i = 0; i < n; i++)
    {
        cout << dp[i] << ' ';
    }
    cout << endl;
    if(dp[n-1] == INT_MAX)
    {
        return -1;
    }
    return dp[n-1];
}
int main()
{
    vector<int> nums = {7, 4, 4, 2, 6, 6, 3, 4};
    cout << frogJump(nums.size(), nums) << endl;
    return 0;
}