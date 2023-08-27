#include <bits/stdc++.h>
using namespace std;

int calculate(string s)
{
    stack<int> st;
    int sum = 0;
    int sign = 1;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] >= '0' and s[i] <= '9')
        {
            int num = 0;
            while(s[i] >= '0' and s[i] <= '9' and i < s.size())
            {
                num = num*10+(s[i] -'0');
                i++;
            }
            sum += sign*num;
            i--;
        }
        else if(s[i] == '+')
        {
            sign = 1;
        }
        else if(s[i] == '-')
        {
            sign = -1;
        }
        else if(s[i] == '(')
        {
            st.push(sum);
            st.push(sign);
            sum = 0;
            sign = 1;
        }
        else if(s[i] == ')')
        {
            sum *= st.top();
            st.pop();
            sum += st.top();
            st.pop();
        }
    }
    return sum;
}

int main()
{
    string s;
    cin >> s;
    cout << calculate(s) << endl;
    return 0;
}