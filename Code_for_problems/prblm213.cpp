#include <bits/stdc++.h>
using namespace std;



int rob(vector<int>&nums)
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
    for(int i = 1; i <n; i++)
    {
        int temp = max(nums[i]+r1, r2);
        r1 = r2;
        r2 = temp;
    }
    int withoutbegin  = r2;
    r1 = 0, r2 = 0;
    for(int i = 0; i <n-1; i++)
    {
        int temp = max(nums[i]+r1, r2);
        r1 = r2;
        r2 = temp;
    }
    return max(withoutbegin, r2);
}

int main()
{
    vector<int> nums = {2,3,2};
    cout << rob(nums) << endl;
    return 0;
}