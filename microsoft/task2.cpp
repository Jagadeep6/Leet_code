#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> &A) 
{
    sort(A.begin(), A.end());
    int res = 1, n = A.size();
    for(int i = 0; i < n; i++)
    {
        for(int j = i; j < n; j++)
        {
            int dif = A[j]-A[i];
            int cur = j, cnt = 1;
            for(int k = j; k < n; k++)
            {
                if(A[k]-A[cur] == dif)
                {
                    cur = k;
                    cnt++;
                }
            }
            res = max(cnt, res);
        }
    }
    cout << res << endl;
    return res;   
}

int main()
{
    vector<int> A = {4, 7, 5, 3, 1};
    cout << solution(A);
}