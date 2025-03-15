#include <iostream>
#include <stack>
#include <math.h>
using namespace std;
int postFix(string s)
{
    stack<int> st;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] >= '0' && s[i] <= '9')
        {
            st.push(s[i] - '0');
        }
        else
        {
            int oper2 = st.top();
            st.pop();
            int oper1 = st.top();
            st.pop();
            switch (s[i])
            {
            case '+':
                st.push(oper1 + oper2);
                break;
            case '-':
                st.push(oper1 - oper2);
                break;
            case '*':
                st.push(oper1 * oper2);
                break;
            case '/':
                st.push(oper1 / oper2);
                break;
            case '^':
                st.push(pow(oper1, oper2));
                break;
            }
        }
    }
    return st.top();
}
int main()
{
    string s;
    cin >> s;
    cout << postFix(s) << endl;
}