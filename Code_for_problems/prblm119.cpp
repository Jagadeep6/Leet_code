#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> getRow(int rowIndex)
    {
        vector<int> temp1 = {1};
        vector<int> temp2 = {1,1};
        if(rowIndex == 0)
        {
            return temp1;
        }
        else if(rowIndex == 1)
        {
            return temp2;
        }
        for(int i = 2; i < rowIndex+1; i++)
        {
            temp1.clear();
            temp1.push_back(1);
            for(int j = 0; j < temp2.size()-1; j++)
            {
                temp1.push_back(temp2[j]+temp2[j+1]);
            }
            temp1.push_back(1);
            swap(temp1, temp2);
        }
        return temp2;
    }
};