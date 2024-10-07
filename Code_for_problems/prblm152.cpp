#include <bits/stdc++.h>
using namespace std;

int maxProduct(vector<int> &nums)
{
    int res = nums[0];
    int cur_min = 1;
    int cur_max = 1;
    for(int i = 0; i < nums.size(); i++)
    {
        int temp = nums[i];
        int prev = cur_max*temp;
        cur_max = max({cur_max*temp, cur_min*temp, temp});
        cur_min = min({cur_min*temp, temp, cur_max*temp});
        res = max(cur_max, res);
    }
    return res;
}

int main()
{

}