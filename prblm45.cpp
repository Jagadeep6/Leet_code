#include <bits/stdc++.h>
using namespace std;

int jump(vector<int> &nums)
{
    int ans = 0;
    for(int i = 1; i < nums.size(); i++)
    {
        nums[i] = max(nums[i] + i, nums[i-1]);
    }
    int i = 0;
    while(i < nums.size()-1)
    {
        i = nums[i];
        ans++;
    }
    return ans;
}

int main()
{
    vector<int> nums = {2,3,0,1,4};
    cout << jump(nums) << endl;
    return 0;
}