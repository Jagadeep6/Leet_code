#include <bits/stdc++.h>
using namespace std;

string simplifyPath(string path)
{
    stack<string> st;
    for(int i = 0; i < path.size(); i++)
    {
        if(path[i] == '/')
        {
            continue;
        }
        string cur = "";
        while(path[i] != '/' and i < path.size())
        {
            cur += path[i];
            i++;
        }

        if(cur == ".")
        {
            continue;
        }
        else if(cur == "..")
        {
            if(!st.empty())
            {
                st.pop();
            }    
        }
        else
        {
            st.push(cur);
        }
    }
    string res = "";
    while(!st.empty())
    {
        res = "/" +st.top() +res;
        st.pop();
    }
    if(res.size() == 0)
    {
        return "/";
    }

    return res;
}

int main()
{
    cout << simplifyPath("/home/") << endl;
    cout << simplifyPath("/../") << endl;
    cout << simplifyPath("/home//foo/") << endl;
    return 0;
}