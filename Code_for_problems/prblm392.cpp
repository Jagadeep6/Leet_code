#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isSubsequence(string s, string t)
    {
        for (int i = 0; i < s.length(); i++)
        {
            int cnt = 0;
            for (int j = cnt + 1; j < t.length(); j++)
            {
                if (s[i] == t[j])
                {
                    cnt = j;
                    if (t[j] == s[s.length() - 1])
                    {
                        return true;
                    }
                    break;
                }
                if (j == t.length() - 1 and t[j] != s[s.length() - 1])
                {
                    return false;
                }
            }
        }
        return false;
    }
};

bool isSubsequence(string s, string t)
{
    int cnt = 0;
    for (int i = 0; i < s.length(); i++)
    {
        for (int j = cnt + 1; j < t.length(); j++)
        {
            if (s[i] == t[j])
            {
                cnt = j;
                cout << cnt << '!';
                if (t[j] == s[s.length() - 1])
                {
                    return true;
                }
                break;
            }
            if (j == t.length() - 1 and s[i] != t[cnt])
            {
                return false;
            }
        }
    }
    return false;
}
//So the fuckking solution is This one is the one right and simple solution
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n = t.length();
        int j = 0;
        for(int i=0; i<n; i++){
            if(s[j] == t[i]){
                j++;
            }
        }
        if(j == s.length()){
            return true;
        }
        return false;
    }
};
int main()
{
    string s;
    string t;
    cin >> s >> t;
    cout << isSubsequence(s, t) << endl;
    return 0;
}