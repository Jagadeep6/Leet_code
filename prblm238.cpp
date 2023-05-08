#include <bits/stdc++.h>
using namespace std;
/*
vector<int> product(vector<int> nums)
{
    int prt = accumulate(nums.begin(), nums.end(), 1, multiplies<int>());
    vector<int> sol(nums.size(), 0);
    for(int i = 0; i < nums.size(); i++)
    {
        sol[i] = prt/nums[i];
    }
    return sol;
}
This doesn't work for a case there is a zero in the array
*/
// Test case : [-1,1,0,-3,3]
// result : [0,0,9,0,0]

vector<int> productExcept(vector<int> nums)
{
    int n = nums.size();
    vector<int> sol(n, 0);
    int prt = 1;
    for(int i = 0; i < n; i++)
    {
        prt*= nums[i];
        sol[i] = prt;
    }

    prt = 1;
    for(int i = n-1; i > 0; i--)
    {
        sol[i]=sol[i-1]*prt;
        prt *= nums[i];
    }
    sol[0] = prt;
    return sol;
}

int main()
{
    int n;
    cin >> n;
    vector<int> nums(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    vector<int> sol = productExcept(nums);
    for (int i = 0; i < sol.size(); i++)
    {
        cout << sol[i] << ' ';
    }
    cout << endl;
    return 0;
}