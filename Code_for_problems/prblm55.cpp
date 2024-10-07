#include <bits/stdc++.h>
using namespace std;

bool canJump(vector<int> &nums)
{
    int n = nums.size();
    int reach = 0;
    for(int i = 0; i < n; i++)
    {
        if(reach < i)
        {
            return false;
        }
        reach = max(reach, i +nums[i]);
        cout << reach << ' ' << i << endl;
        if(reach >= n-1)
        {
            return true;
        }
    }
    cout << endl;
    return false;
}

int main()
{
    vector<int> nums = {2, 3, 1, 1, 4, 1, 2, 0, 5, 6};
    cout << canJump(nums) << endl;
    return 0;
}