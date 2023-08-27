#include <bits/stdc++.h>
using namespace std;

int minSubArrayLen(int target, vector<int>& nums)
{
    int n = nums.size();
    int sum = 0, len = INT_MAX;
    int left = 0;
    for(int i = 0; i < n; i++)
    {
        sum += nums[i];
        while(sum >= target and i < n)
        {
            len = min(len, i-left+1);
            sum -= nums[left];
            left++;
        }
    }        
    if(len == INT_MAX)
    {
        return 0;
    }
    return len;
}

int main()
{
    
}