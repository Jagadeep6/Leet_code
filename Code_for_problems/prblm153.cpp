#include <bits/stdc++.h>
using namespace std;

int findMin(vector<int> &nums)
{
    int s = 0;
    int e = nums.size();
    int res = nums[0];
    while(s <= e)
    {
        if(nums[s] < nums[e])
        {
            res = min(res, nums[s]);
            break;
        }
        int mid = s+(e-s)/2;
        res = min(res, nums[mid]);
        if(nums[mid] >= nums[mid+1])
        {
            s = mid+1;
        }
        else
        {
            e = mid-1;
        }
    }
    return res;
}

int main()
{

}