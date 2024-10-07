#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target)
    {
        vector<int> sol(2);
        for(int i = 0; i < nums.size(); i++)
        {
            for(int j = 0; j < nums.size(); j++)
            {
                int sum = nums[i] + nums[j];
                if(sum == target and sol[i] != sol[j])
                {
                    sol[0] = i;
                    sol[1] = j;
                    return sol;
                }
            }
        }   
    }
};

int main()
{

}