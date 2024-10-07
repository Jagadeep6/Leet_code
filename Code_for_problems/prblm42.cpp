#include <bits/stdc++.h>
using namespace std;

int trap(vector<int> &height)
{
    int n = height.size();
    vector<int> max_l(n, 0);
    vector<int> max_r(n, 0);
    max_l[0] = height[0];
    max_r[n - 1] = height[n - 1];
    for (int i = 1; i < n; i++)
    {
        max_l[i] = max(max_l[i - 1], height[i]);
        max_r[n-i-1] = max(max_r[n-i], height[n-i-1]);
    }
    int water = 0;
    for (int i = 0; i < n; i++)
    {
        water += min(max_l[i], max_r[i]) - height[i];
    }
    return water;
}