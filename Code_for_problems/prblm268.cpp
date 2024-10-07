#include <bits/stdc++.h>
using namespace std;

int missing_number(vector <int> nums)
{
    int max_num = int(*max_element(nums.begin(), nums.end()));
    vector<bool> ar_tr(max_num, 0);
    for(int i = 0; i < nums.size(); i++)
    {
        ar_tr[nums[i]] = true;
    }
    for(int i = 0; i < max_num;i++)
    {
        if(ar_tr[i]==false)
        {
            return i;
        }
    }
}
int main()
{
    int n;
    cin >> n;
    int a;
    vector <int> nums(n, 0);
    for(int i = 0; i < n; i++)
    {
        cin >> nums[i];
        // nums.push_back(a);
    }
    cout << missing_number(nums);
    return 0;
}