#include <bits/stdc++.h>
using namespace std;

int evalRPN(vector<string> &tokens)
{
    stack<int> st;
    for (int i = 0; i < tokens.size(); i++)
    {
        string s = tokens[i];
        if(s.size() > 1 or isdigit(s[0]))
        {
            st.push(stoi(s));
            continue;
        }
        int x = st.top();
        st.pop();
        int y = st.top();
        st.pop();
        if(tokens[i] == "+")
        {
            st.push(x+y);
        }
        else if(tokens[i] == "-")
        {
            st.push(y-x);
        }
        else if(tokens[i] == "*")
        {
            st.push(x*y);
        }
        else
        {
            st.push(y/x);
        }
    }
    return st.top();
}

int main()
{
}