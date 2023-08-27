#include <bits/stdc++.h>
using namespace std;

int hIndex(vector<int> &citations)
{
    int h = 0;
    sort(citations.begin(), citations.end());
    //0, 1, 3, 5, 6
    if(citations[0] > citations.size()-1)
    {
        return citations.size();
    }
    if(citations.size() == 1)
    {
        return !(citations[0] == 0);
    }
    for(int i = 0; i < citations.size(); i++)
    {
        if(citations[i] > citations.size() - i)
        {
            h = citations.size() - i;
            break;
        }
    }
    return h;
}