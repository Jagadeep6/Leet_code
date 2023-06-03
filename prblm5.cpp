#include <bits/stdc++.h>
using namespace std;

string longestPalindrome(string s)
{
    int max_start = 0;
    int max_len = 1;

    for(int i = 0; i < s.size(); i++)
    {
        check_palindrome_from_middle(s, i, i, max_start, max_len);
        check_palindrome_from_middle(s, i, i+1, max_start, max_len);
    }

    return s.substr(max_start, max_len);
}

void check_palindrome_from_middle(string s, int i, int j, int &max_start, int &max_len)
{
    while(i >= 0 and j <= s.size()-1 and s[i] == s[j])
    {
        i--;
        j++;
    }
    if(j-i-1 > max_len)
    {
        max_start = i+1;
        max_len = j-i-1;
    }
}

int main()
{

}