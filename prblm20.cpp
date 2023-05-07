#include <bits/stdc++.h>
using namespace std;

bool valid(char a, char b)
{
    if(a == '(' and b == ')')
    {
        return true;
    }
    else if(a == '[' and b == ']')
    {
        return true;
    }
    else if(a == '{' and b == '}')
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool valid_par(string par)
{
    stack<char> st;
    st.push(par[0]);
    for(int i = 1; i < par.length(); i++)
    {
        if(st.empty())
        {
            st.push(par[i]);
        }
        else if(valid(st.top(), par[i]))
        {
            st.pop();
        }
        else
        {
            st.push(par[i]);
        }
    }

    if(st.empty())
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    string par;
    cin >> par;
    valid_par(par) ? cout << "yes" : cout << "no";

    return 0; 
}