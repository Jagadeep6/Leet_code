#include <bits/stdc++.h>
using namespace std;

string remove_dup(string s)
{
    stack <char> st;
    string o = "";
    for(int i = 0; i < s.length(); i++)
    {   
        if(st.empty())
        {
            st.push(s[i]);
        }
        else
        {
            if(st.top() == s[i])
            {
                st.pop();
            }
            else
            {   
                st.push(s[i]);
            }
        }
    }

    stack <char> r;
    while(!st.empty())
    {
        r.push(st.top());
        st.pop();
    }
    while (!r.empty())
    {
        o += r.top();
        r.pop();
    }
    
    return o;
}

int main()
{
    string s;
    cin >> s;
    cout << remove_dup(s);
    return 0;
}