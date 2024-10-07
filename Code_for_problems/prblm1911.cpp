#include <bits/stdc++.h>
using namespace std;
long long maxAlternatingSum(vector<int> &nums)
{
    long long even = 0, odd = 0;
    for(int i = nums.size()-1; i>=0; i--)
    {
        long long temp_even = max(odd+nums[i], even);
        long long temp_odd = max(even-nums[i], odd);
        even = temp_even;
        odd = temp_odd;
    }
    return even;
}
int main()
{
    vector<int> nums = {4, 2, 5, 3};
    cout << maxAlternatingSum(nums);
}