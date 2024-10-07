#include <bits/stdc++.h>
using namespace std;
int minEatingSpeed(vector<int> &piles, int h)
{
    int s = 1;
    int end =*max_element(piles.begin(), piles.end());
    while(s <= end)
    {   
        int mid = s+(end - s)/2;
        if(canEatInTime(piles, mid, h))
        {
            end = mid-1;
        }       
        else
        {
            s = mid+1;
        } 
    }   
    return s;
}

bool canEatInTime(vector<int> piles, int k, int h)
{
    int hrs = 0;
    for(auto i : piles)
    {
        hrs += i/k;
        if(i %k != 0)
        {
            hrs++;
        }
    }

    return hrs <= h;
}
int main()
{
}