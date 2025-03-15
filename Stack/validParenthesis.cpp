#include <iostream>
#include <stack>
using namespace std;
bool isValidString(string s)
{
    bool ans = true;
    stack<char> st;
    int n = s.length();
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{')
        {
            st.push(s[i]);
        }
        else if (s[i] == ')')
        {
            if (!st.empty() && st.top() == '(')
            {
                st.pop();
            }
            else
            {
                ans = false;
                break;
            }
        }
        else if (s[i] == '}')
        {
            if (!st.empty() && st.top() == '{')
            {
                st.pop();
            }
            else
            {
                ans = false;
                break;
            }
        }
        else if (s[i] == ']')
        {
            if (!st.empty() && st.top() == '[')
            {
                st.pop();
            }
            else
            {
                ans = false;
                break;
            }
        }
    }
    if (!st.empty())
    {
        ans = false;
    }
    return ans;
}
int main()
{
    string s;
    cin >> s;
    if (isValidString(s))
    {
        cout << "Valid string." << endl;
    }
    else
    {
        cout << "Not valid string." << endl;
    }
}