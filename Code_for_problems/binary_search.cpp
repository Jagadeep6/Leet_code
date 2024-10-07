#include <bits/stdc++.h>
using namespace std;

int binary_search(vector<int> nums, int target)
{   
    int left = 0, right = nums.size();
    while(left <= right)
    {
        int mid = left + (right-1)/2;
        if(nums[mid] == target)
        {
            return mid;
        }
        if(nums[mid] > target)
        {
            right = mid - 1;  
        }
        else
        {
            left = mid + 1;
        }
    }
    return -1;
}

int main()
{
    int n;
    int target;
    cin >> n;
    vector<int> nums(n, 0);
    cin >> target;
    for(int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    // for(int i = 0; i < n; i++)
    // {
    //     cout << nums[i] << ' ';
    // }
    cout << binary_search(nums, target);
    return 0;
}