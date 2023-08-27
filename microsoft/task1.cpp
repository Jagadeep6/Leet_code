// you can use includes, for example:
// #include <algorithm>
#include <bits/stdc++.h>
using namespace std;
// namespace std;

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
vector<pair<int, int>> dir = {{2, 0}, {1, -1}, {0, -2}};
bool isPossible(vector<int> A, int l, int r, int n, int sum)
{
    for(int i = 0; i < 3; i++)
    {
        if(A[l+dir[i].first]+A[r+dir[i].second] == sum) return true; 
    }
    return false;
}

void solve(vector<int> A, int l, int r, int &moves, int cur, int sum, int n)
{
    if(l > r or !isPossible(A, l, r, n, sum) or r-l < 2)
    {
        return;
    }
    for(int k = 0; k < 3; k++)
    {
        int new_l = l+dir[k].first;
        int new_r = r+dir[k].second;
        if(sum == A[new_l]+A[new_r])
        {
            moves = max(cur+1, moves);
            solve(A, new_l, new_r, moves, cur+1, sum, n);
        }
    }
}

int solution(vector<int> &A) {
    int n = A.size();
    if(n < 2)
    {
        return 0;
    }
    vector<int> possible = {A[0]+A[1], A[0]+A[n-1], A[n-1]+A[n-2]};
    int moves = 1;
    for(int k = 0; k < 3; k++)
    {
        int left = 0, right = n-1;
        bool further = true;
        if(k == 0) left+= 2;
        else if(k == 1)
        {
            left++;
            right--;
        }
        else right -= 2;
        int sum = possible[k];
        solve(A, left, right, moves, 1, sum, n);
    }
    cout << moves << endl;
    return moves;
}
