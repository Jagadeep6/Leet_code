#include <bits/stdc++.h>
using namespace std;

vector<int> spiralOrder(vector<vector<int>> &matrix)
{
    int m = matrix.size();
    int n = matrix[0].size();
    vector<int> res;
    if (matrix.empty() or matrix[0].empty())
    {
        return res;
    }
    int top = 0, right = n - 1, left = 0, bottom = m - 1;

    while (top <= bottom and left <= right)
    {
        for(int i = left; i <= right; i++)
        {
            res.push_back(matrix[top][i]);
        }
        top++;
        for(int i = top; i <= bottom; i++)
        {
            res.push_back(matrix[i][right]);
        }
        right--;

        if(top <= bottom)
        {
            for(int i = right; i >= left; i--)
            {
                res.push_back(matrix[bottom][i]);
            }
            bottom--;
        }
        if(left <= right)
        {
            for(int i = bottom; i>= top; i--)
            {
                res.push_back(matrix[i][left]);
            }
            left++;
        }
    }

    return res;
}

int main()
{
    vector<vector<int>> matrix = {{1,2,3},{4,5,6},{7,8,9}};
    vector<int> res = spiralOrder(matrix);
    for(int i = 0; i < res.size(); i++)
    {
        cout << res[i] << ' ';
    }
    cout <<endl;
    return 0;
}