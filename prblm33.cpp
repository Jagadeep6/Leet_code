#include <bits/stdc++.h>
using namespace std;

int search(vector<int> nums, int target)
{
    int s = 0, e = nums.size() - 1;
    int mid = s+e/2;
    while (s <= e)
    {
        mid = (s+e)/2;
        if(target == nums[mid])
        {
            return mid;
        }
        if(nums[s] <= nums[mid])
        {
            if(nums[s] <= target && nums[mid] >= target)
            {
                e = mid-1;
            }
            else
            {
                s = mid+1;
            }
        }
        else
        {
            if(nums[e] >= target and nums[mid] <= target)
            {
                s = mid+1;
            }
            else
            {
                e = mid-1;
            }
        }
    }

    return -1;
}

int main()
{
    int n;
    int target;
    cin >> n >> target;
    vector<int> nums(n, 0);
    for(int i = 0; i < n; i++)
    {
        cin >> nums[i];   
    }
    for(int i = 0; i < n; i++)
    {
        cout << nums[i];   
    }
    cout << search(nums, target) << endl;
    return 0;
}