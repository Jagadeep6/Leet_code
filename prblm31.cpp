#include <bits/stdc++.h>
using namespace std;

void nextpemutation(vector<int> nums)
{
    int n = nums.size(), k, l;
    for(int i = n- 2; k >= 0; k--)
    {
        if(nums[k] , nums[k+1])
        {
            break;
        }
    }
    if(k < 0)
    {
        reverse(nums.begin(), nums.end());
    }
}

int main()
{
    
}