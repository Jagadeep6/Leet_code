#include <bits/stdc++.h>
using namespace std;

int rob(vector<int> &nums)
{
    int n = nums.size();
    if(nums.size() == 1)
    {
        return nums[0];
    }
    if(nums.size() == 2)
    {
        return max(nums[0], nums[1]);
    }
    int r1 = 0, r2 = 0;
    for(int i = 0; i <n; i++)
    {
        int temp = max(nums[i]+r1, r2);
        r1 = r2;
        r2 = temp;
    }
    return r2;
}

int main()
{
    vector<int> nums = {1,2,3,1};
    cout << rob(nums) << endl;
    return 0;
}