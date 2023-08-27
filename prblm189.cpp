#include <bits/stdc++.h>
using namespace std;

void rotate(vector<int> &nums, int k)
{
    int n = nums.size();
    if(k > n)
    {
        k = k%n;
    }
    // for(int i = 0; i < k; i++)
    // {
    //     for(int j = 0; j < nums.size(); j++)
    //     {
    //         swap(nums[j], nums[n-1]);       
    //     }
    // }

    //or else

    reverse(nums.begin(), nums.begin()+n-k);
    reverse(nums.begin()+n-k, nums.end());
    reverse(nums.begin(), nums.end());
    
    return;
}

int main()
{
    vector<int> nums = {1,2,3,4,5,6,7};
    rotate(nums, 3);
    for(int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << ' ';
    }
    cout << endl;
    return 0;
}