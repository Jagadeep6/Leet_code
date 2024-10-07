#include <bits/stdc++.h>
using namespace std;

int base(char c)
{
    if(c == 'I')
    {
        return 1;
    }
    else if(c == 'V')
    {
        return 5;
    }
    else if(c == 'X')
    {
        return 10;
    }
    else if(c == 'L')
    {
        return 50;
    }
    else if(c == 'C')
    {
        return 100;
    }
    else if(c == 'D')
    {
        return 500;
    }
    else if(c == 'M')
    {
        return 1000;
    }
    else
    {
        return -1;
    }
}

int romantoint(string s)
{
    stack<char> ch;
    int num = 0;
    ch.push(s[0]);
    for(int i = 1; i < s.length(); i++)
    {
        if(ch.empty())
        {
            ch.push(s[i]);
        }
        else
        {
            if(base(ch.top()) < base(s[i]))
            {
                int c = base(s[i]) - base(ch.top());
                num += c;
                ch.pop();
            }
            else
            {
                int c = base(ch.top());
                num += c;
                ch.pop();
                ch.push(s[i]);
            }
        }
    }
    return num;
}

int main()
{
    string s;
    cin >> s;
    cout << s.length() << endl;
    cout << romantoint(s) << endl;
    return 0;
}