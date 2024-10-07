#include <bits/stdc++.h>
using namespace std;

bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    int m = matrix.size(),
        n = matrix[0].size();

    int curr = 0, curc = n-1;

    while(curr < m and curc >= 0)
    {
        int temp = matrix[curr][curc];
        if(temp == target)
        {
            return true;
        }
        else if(temp < target)
        {
            curr++;
        }
        else
        {
            curc--;
        }
    }

    return false;
}