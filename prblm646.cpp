#include <bits/stdc++.h>
using namespace std;
static bool comp(vector<int> p1, vector<int> p2)
{
    return p1[1] < p2[1];
}
int findLongestChain(vector<vector<int>> &pairs)
{
    sort(pairs.begin(), pairs.end(), comp);
    int cnt = 1;
    int s = 0;
    for(int i = 1; i < pairs.size(); i++)
    {
        if(pairs[s][1] < pairs[i][0])
        {
            s = i;
            cnt++;
        }
    }
    return cnt;
}

int main()
{
    vector<vector<int>> nums = {{1, 2}, {7,8}, {4, 5}};
    cout <<findLongestChain(nums) << endl;
    return 0;
}