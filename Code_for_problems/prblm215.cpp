#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) 
    {
        priority_queue<int> hp;
        for(int i = 0; i < nums.size(); i++)
        {
            hp.push(nums[i]);
        }

        for(int i = 0; i < k-1; i++)
        {
            hp.pop();
        }

        return hp.top();
    }
};

int main()
{

}