#include <bits/stdc++.h>
using namespace std;

int countSubstrings(string s)
{
    int res = 0;
    for(int i = 0; i < s.size(); i++)
    {
        count_palindromes(s, res, i, i);
        count_palindromes(s, res, i, i+1);
    }
    return res;
}

void count_palindromes(string s, int &res, int i, int j)
{
    while(i >= 0 and j < s.size()-1 and s[i] == s[j])
    {
        i++;
        j--;
        res++;
    }
}

int main()
{

}