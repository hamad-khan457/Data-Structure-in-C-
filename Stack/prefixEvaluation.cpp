#include <iostream>
#include <stack>
#include <math.h>
using namespace std;
int prefixEvaluation(string s)
{
    stack<int> st;
    for (int i = s.length() - 1; i >= 0; i--)
    {
        if (s[i] >= '0' && s[i] <= '9')
        {
            st.push(s[i] - '0');
        }
        else
        {
            int oper1 = st.top();
            st.pop();
            int oper2 = st.top();
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
    cout << prefixEvaluation("-+7*45+20") << endl;
    return 0;
}