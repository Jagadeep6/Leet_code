#include <bits/stdc++.h>
using namespace std;

int maxArea(vector<int> &height)
{
    int j = height.size()-1;
    int i = 0, cur = 0, res = 0;
    while(i < j)
    {
        cur = (j-i)*min(height[i], height[j]);
        res = max(res, cur);
        if(height[i] <= height[j])
        {
            i++;
        }
        else
        {
            j--;
        }
    }
    return res;
}