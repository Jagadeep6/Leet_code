#include <bits/stdc++.h>
using namespace std;

void nextPermutation(vector<int> &nums)
{
    int n = nums.size(), ind = -1;
    for(int i = n-2; i >= 0; i--)
    {
        if(nums[i] < nums[i+1])
        {
            ind = i;
            break;
        }
    }

    for(int i = n-1; i >= ind and ind != -1; i--)
    {
        if(nums[i] > nums[ind])
        {
            swap(nums[i], nums[ind]);
            break;
        }
    }
    reverse(nums.begin() +ind+1, nums.end());
}

int main()
{
    
}