#include <bits/stdc++.h>
using namespace std;

int longest_valid(string  s)
{
    int c = 0;
    stack<int> st;
    st.push(-1);
    for(int i = 0; i < s.length(); i++)
    {
        if(s[i]== '(')
        {
            st.push(i);
        }
        else
        {
            st.pop();
            if(st.empty())
            {
                st.push(i);
            }
            else
            {
                c = max(c, i - st.top());
            }
        }
    }
    return c;
}

int main()
{
    string s;
    cin >> s;
    cout << longest_valid(s);
    return 0;
}